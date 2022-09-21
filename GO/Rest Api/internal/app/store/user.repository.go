package store

import (
	"github.com/Martirosyan-Hayk/study-projects/Go/internal/app/model"
)

type UserRepository struct {
	store *Store
}

func (userRepository *UserRepository) Create(user *model.User) (*model.User, error) {
	if err := userRepository.store.db.QueryRow(
		"INSERT INTO users (email, password) VALUES ($1, $2) RETURNING id",
		user.Email, user.Password).Scan(&user.ID); err != nil {
		return nil, err
	}

	return user, nil
}

func (userRepository *UserRepository) FindById(id int) (*model.User, error) {
	userRepository.store.db.QueryRow("SELECT * FROM users WHERE id = $1 RETURNING *", id)

	return nil, nil
}

func (userRepository *UserRepository) FindByEmail(email string) (*model.User, error) {
	user := &model.User{}

	if err := userRepository.store.db.QueryRow(
		"SELECT * FROM users WHERE email = $1",
		email).Scan(&user.ID, &user.Email, &user.Password, &user.CreatedAt, &user.UpdatedAt);  err != nil {
		return nil, err
	}

	return user, nil
} 