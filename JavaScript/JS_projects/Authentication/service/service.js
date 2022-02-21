import db from '../db.js';
import bcrypt from 'bcrypt';
import jwtToken  from '../utils/jwtHelpers.js';


let regex = new RegExp('[a-z0-9]+@[a-z]+\.[a-z]{2,3}');

class Service {
    async register(req, res) {
        const { name, email, password, admin } = req.body;
        if (!regex.test(email)) {
            throw new Error('Email is incorrect');
        }

        const hashedPassword = await bcrypt.hash(password, 10);
        await db.query(
            `INSERT INTO users (name, email, password, admin) values ($1, $2, $3, $4) RETURNING *`,
            [name, email, hashedPassword, admin], function (err, result) {
                if (err) {
                    res.status(401).send({ error: err.message });
                }
                else {
                    res.status(200).json({ user: result.rows[0] });
                }
            });
    };

    async login(req, res) {
        const { email, password } = req.body;
        const user = await db.query(`SELECT * FROM users WHERE email = $1`, [email]);

        if (!user.rows[0]) {
            throw new Error('Email is incorrect. User not found');
        }
        //PASSWORD CHECK
        const validPassword = await bcrypt.compare(password, user.rows[0].password);
        if (!validPassword) {
            throw new Error('Password is incorrect. User not found');
        }
        //JWT TOKEN
        let token = jwtToken({ user_id: user.rows[0].id, user_name: user.rows[0].name, user_email: user.rows[0].email });
        res.cookie('refresh_token', token.refreshToken, { httpOnly: true });
        res.status(200).json(token);
    };

    async get(req, res) {
        const email = req.params.email;
        const user = await db.query(`SELECT * FROM users WHERE email = $1`, [email]);

        if (!user.rows[0]) {
            throw new Error('Email is incorrect. User not found');
        }

        if (user.rows[0].admin === false) {
            res.status(405).send('You are not admin and you can not get users');
        }

        const users = await db.query(`SELECT * FROM users`);
        if (!users.rows[0]) {
            throw new Error('Users not found');
        }
        res.status(200).json({ users: users.rows });
    };

    async delete(req, res) {
        const email = req.params.email;
        const user = await db.query(`SELECT * FROM users WHERE email = $1`, [email]);

        if (!user.rows[0]) {
            throw new Error('Email is incorrect. Admin not found');
        }

        if (user.rows[0].admin === false) {
            res.status(405).send('You are not admin and you can not delete users');
        }

        const deletableUserEmail = req.params.deletableUserEmail;
        const deletableUser = await db.query(`SELECT * FROM users WHERE email = $1`, [deletableUserEmail]);

        if (!deletableUser.rows[0]) {
            throw new Error('Email is incorrect. User not found');
        }

        if (deletableUser.rows[0].admin === true) {
            res.status(405).send('You can not delete admin');
        }

        await db.query(`DELETE FROM users WHERE email = $1`, [deletableUserEmail]);
        res.status(200).json({ "deleted user": deletableUserEmail });
    }
}

export default new Service();