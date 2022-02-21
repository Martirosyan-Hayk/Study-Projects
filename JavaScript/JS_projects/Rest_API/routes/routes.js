import Router from 'express';
import userController from '../controller/controller.js';
const router = new Router();

router.post('/user', userController.createUser);
router.get('/user', userController.getUsers);
router.get('/user/:id', userController.getUserById);
router.put('/user', userController.updateUser);
router.delete('/user/:id', userController.deleteUser);

export default router