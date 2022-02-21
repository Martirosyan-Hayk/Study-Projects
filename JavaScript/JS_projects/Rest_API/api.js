import dotenv from 'dotenv';
import userRouter from './routes/routes.js';
import express from 'express';

dotenv.config();
const app = express();
const port = process.env.PORT || 3000;

app.use(express.json());

app.use('/api', userRouter);

app.listen(port, () => {
        console.log(`Server is running on port ${port}.`);
});