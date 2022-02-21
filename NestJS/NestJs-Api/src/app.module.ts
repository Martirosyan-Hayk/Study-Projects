import { Module } from '@nestjs/common';
import { TypeOrmModule } from '@nestjs/typeorm';
import { ConfigModule } from '@nestjs/config';
import { UserEntity } from './users/user.entity';
import { UserSubscriber } from './entity-subscribers/user-subscriber';
// import { UserModule } from './users/user.module';
import { UserModule } from './users/user.module';

@Module({
  imports: [
    UserModule,
    ConfigModule.forRoot({
      envFilePath: `${process.cwd()}/src/.env`,
    }),
    TypeOrmModule.forRoot({
      type: 'postgres',
      host: process.env.DATABASE_HOST,
      port: Number(process.env.DATABASE_PORT),
      username: process.env.DATABASE_USERNAME,
      password: process.env.DATABASE_PASSWORD,
      database: process.env.DATABASE_NAME,
      synchronize: false,
      subscribers: [UserSubscriber],
      entities: [UserEntity],
      migrations: ['src/migrations/*{.ts,.js}'],
    }),
  ],
  controllers: [],
  providers: [],
})
export class AppModule {}
