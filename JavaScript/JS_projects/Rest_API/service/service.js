import db from '../db.js';
import bcrypt from 'bcrypt';

let regex = new RegExp('[a-zA-Z0-9_][a-zA-Z0-9_.]');

class Service {
    async create(req, res) {
        const { name, lastname, username, password } = req.body;
        
        if (!regex.test(username)) {
            throw new Error('Username is incorrect');
        }

        const hashedPassword = await bcrypt.hash(password, 10);
        await db.query(
            `INSERT INTO users (name, lastname, username, password) values ($1, $2, $3, $4) RETURNING *`,
            [name, lastname, username, hashedPassword], function (err, result) {
                if (err) {
                    res.status(401).send({ error: err.message });
                }
                else {
                    res.status(200).json({ user: result.rows[0] });
                }
            });
    };

    async getById(req, res) {
        const username = req.params.username;
        const user = await db.query(`SELECT * FROM users WHERE username = $1`, [username]);

        if (!user.rows[0]) {
            throw new Error('Username is incorrect. User not found');
        }
        res.status(200).json({ user: user.rows[0] });
    };

    async get(req, res) {
        const users = await db.query(`SELECT * FROM users`);
        if (!users.rows[0]) {
            throw new Error('Users not found');
        }
        res.status(200).json({ users: users.rows });
    };

    async update(req, res) { 
        const {username, name, lastname, password } = req.body;
        const user = await db.query(`UPDATE users set name = $2, lastname = $3, password = $4 where username = $1 RETURNING * `, [username, name, lastname, password]);
        
        if (!user.rows[0]) {
            throw new Error('Username is incorrect. User not found');
        }
        res.status(200).json({ "updated user": user.rows[0] });
    };

    async delete(req, res) {
        const username = req.params.username;
        const user = await db.query(`DELETE FROM users WHERE username = $1`, [username]);

        if (!user.rows[0]) {
            throw new Error('Username is incorrect. User not found');
        }
        res.status(200).json({ "deleted user": user.rows[0] });
    };
}

export default new Service();