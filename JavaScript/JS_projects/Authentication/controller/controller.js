import service from '../service/service.js';

class userController {

    async registerUser(req, res) {
        try {
            await service.register(req, res);
        }
        catch (err) {
            res.status(401).send({ error: err.message });
        }
    }
    async loginUser(req, res) {
        try {
            await service.login(req, res);
        }
        catch (err) {
            res.status(404).send({ error: err.message });
        }
    }
    async getUsers(req, res) {
        try {
            await service.get(req, res);
        }
        catch (err) {
            res.status(404).send({ error: err.message });
        }
    }
    async deleteUser(req, res) {

        try {
            await service.delete(req, res);
        }
        catch (err) {
            res.status(404).send({ error: err.message });
        }
    };
}

export default new userController()