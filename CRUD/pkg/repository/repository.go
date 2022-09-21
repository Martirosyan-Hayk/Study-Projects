package repository

import "github.com/jmoiron/sqlx"

type AuthorizationRepository interface {
}

type UserRepository interface {
}

type ProfessionRepository interface {
}

type Repository interface {
	AuthorizationRepository
	UserRepository
	ProfessionRepository
}

func NewRepository(db *sqlx.DB) *Repository {
	return &Repository{};
}