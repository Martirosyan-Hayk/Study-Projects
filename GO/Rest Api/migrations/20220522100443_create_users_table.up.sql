CREATE TABLE users (
  id bigserial not null PRIMARY KEY,
  email varchar(255) not null unique,
  password varchar(255) not null,
  created_at timestamp with time zone not null DEFAULT now(),
  updated_at timestamp with time zone not null DEFAULT now()
);