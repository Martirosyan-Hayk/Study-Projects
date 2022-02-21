CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

create TABLE users(
    id uuid PRIMARY KEY DEFAULT uuid_generate_v4(),
    name text,  
    email text unique,
    password text,
    admin boolean
);  