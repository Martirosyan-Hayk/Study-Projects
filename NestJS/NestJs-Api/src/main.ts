import { HttpStatus, ValidationPipe } from '@nestjs/common';
import { NestFactory } from '@nestjs/core';
import { SwaggerModule, DocumentBuilder } from '@nestjs/swagger';
import { AppModule } from './app.module';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);

  const config = new DocumentBuilder()
    .setTitle('RestAPI')
    .setDescription(
      'A REST API (also known as RESTful API) is \
      an application programming interface (API or web API) that \
      conforms to the constraints of REST architectural style and allows \
      for interaction with RESTful web services. REST stands for representational \
      state transfer and was created by computer scientist Roy Fielding.',
    )
    .setVersion('1.0')
    .addTag('RestAPI')
    .addSecurity('basic', {
      type: 'http',
      scheme: 'basic',
    })
    .build();

  const ducument = SwaggerModule.createDocument(app, config);
  SwaggerModule.setup('api', app, ducument);

  app.useGlobalPipes(
    new ValidationPipe({
      errorHttpStatusCode: HttpStatus.UNPROCESSABLE_ENTITY,
    }),
  );
  const PORT = Number(process.env.PORT) || 3000;
  await app.listen(PORT, () => {
    console.log(`Server run in port ${PORT}`);
  });
}
bootstrap();

// "migration:generate": "ts-node node_modules/typeorm/cli.js migration:generate -f ormconfig -d src/migrations -n",
// "migration:run": "ts-node node_modules/typeorm/cli.js migration:run -f ormconfig",
// "migration:revert": "ts-node node_modules/typeorm/cli.js migration:revert -f ormconfig",
