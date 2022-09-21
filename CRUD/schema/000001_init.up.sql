CREATE TABLE users
(
    id serial not null unique,
    name VARCHAR(255) not null,
    email VARCHAR(255) not null,
    password VARCHAR(255) not null,
    PRIMARY KEY (id)
);

CREATE TABLE professions
(
    id serial not null unique,
    title VARCHAR(255) not null,
    description VARCHAR(255) not null,
    PRIMARY KEY (id)
);


CREATE TABLE users_professions
(
    id serial not null unique,
    user_id INTEGER not null,
    profession_id INTEGER not null,
    PRIMARY KEY (id),
    FOREIGN KEY (user_id) REFERENCES users(id) on delete cascade not null,
    FOREIGN KEY (profession_id) REFERENCES professions(id) on delete cascade not null
);