CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

create TABLE users(
    id uuid PRIMARY KEY DEFAULT uuid_generate_v4(),
    name text,  
    lastname text,
    username text unique,
    password text
);