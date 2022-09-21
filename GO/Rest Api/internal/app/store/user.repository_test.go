package store_test

import (
	"testing"

	"github.com/Martirosyan-Hayk/study-projects/Go/internal/app/model"
	"github.com/Martirosyan-Hayk/study-projects/Go/internal/app/store"
	"github.com/stretchr/testify/assert"
)

func TestUserRepository_Create(t *testing.T){
	s, teardown := store.TestStore(t, databaseURL)
	defer teardown("users")

	u, err := s.User().Create(&model.User{
		Email: "user1@example.com",
		Password: "password",
	})

	assert.NoError(t, err)
	assert.NotNil(t, u)
} 


func TestUserRepository_FindByEmail(t *testing.T){
	s, teardown := store.TestStore(t, databaseURL)
	defer teardown("users")

	_, err := s.User().FindByEmail("user@example.com")
	assert.Error(t, err)

	s.User().Create(&model.User{
		Email: "user@example.com",
		Password: "password",
	})

	u, err := s.User().FindByEmail("user@example.com")
	assert.NoError(t, err)
	assert.NotNil(t, u)
}