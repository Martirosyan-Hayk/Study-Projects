import Router from 'express';
import userController from '../controller/controller.js';
const userRouter = new Router();


userRouter.post('/register', userController.registerUser);
userRouter.post('/login', userController.loginUser);
userRouter.get('/admin/:email', userController.getUsers);
userRouter.delete('/admin/:email/:deletableUserEmail', userController.deleteUser);


export default userRouter