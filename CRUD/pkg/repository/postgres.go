package repository

import (
	"fmt"

	"github.com/jmoiron/sqlx"
)

type Config struct {
	Host string
	Port string
	UserName string
	Password string
	Database string
	SSlMode  string
}

func NewPostgresDB(config Config) (*sqlx.DB, error){
	db, err := sqlx.Open("postgres", fmt.Sprintf("host=%s port=%s user=%s password=%s dbname=%s sslmode=%s", config.Host, config.Port, config.UserName, config.Password, config.Database, config.SSlMode))
	if err != nil {
		return nil, err
	}

	err = db.Ping()

	if err != nil {
		return nil, err
	}

	return db, nil
}