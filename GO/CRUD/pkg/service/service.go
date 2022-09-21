package service

import "github.com/Martirosyan-Hayk/study-projects/Golang/pkg/repository"

type AuthorizationRepository interface {
}

type UserRepository interface {
}

type ProfessionRepository interface {
}

type Service interface {
	AuthorizationRepository
	UserRepository
	ProfessionRepository
}

func NewService(repository *repository.Repository ) *Service {
	return &Service{};
}