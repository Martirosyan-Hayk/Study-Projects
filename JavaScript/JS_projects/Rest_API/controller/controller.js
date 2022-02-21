import service from '../service/service.js';

class userController {

    async createUser(req, res) {
        try {
            await service.create(req, res);
        }
        catch (err) {
            res.status(401).send({ error: err.message });
        }
    }
    async getUsers(req, res) {
        try {
            await service.get(req, res);
        } catch (error) {
            res.status(404).send({ error: error.message });
        }
    }
    async getUserById(req, res) {
        try {
            await service.getById(req, res);
        } catch (error) {
            res.status(404).send({ error: error.message });
        }
    }
    async updateUser(req, res) { 
        try {
            await service.update(req, res);
        } catch (error) {
            res.status(404).send({ error: error.message });
        }
    }
    async deleteUser(req, res) {
        try {
            await service.delete(req, res);
        } catch (error) {
            res.status(404).send({ error: error.message });
        }
    }
}


export default new userController()