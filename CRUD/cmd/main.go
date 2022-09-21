package main

import (
	"log"

	"github.com/Martirosyan-Hayk/study-projects/Golang"
	"github.com/Martirosyan-Hayk/study-projects/Golang/pkg/handler"
	"github.com/Martirosyan-Hayk/study-projects/Golang/pkg/repository"
	"github.com/Martirosyan-Hayk/study-projects/Golang/pkg/service"
	"github.com/spf13/viper"
)

func main() {
	if err := initConfig(); err != nil {
		log.Fatalf("error initializing configs: %s", err.Error())
	}

	db, err := repository.NewPostgresDB(repository.Config{
		Host:     viper.GetString("postgres.host"),
		Port:     viper.GetString("postgres.port"),
		UserName: viper.GetString("postgres.user_name"),
		Password: viper.GetString("postgres.password"),
		Database: viper.GetString("postgres.database"),
		SSlMode:  viper.GetString("postgres.ssl_mode"),
	})
	if err != nil {
		log.Fatalf("error initializing db: %s", err.Error())
	}


	repository := repository.NewRepository(db)
	service := service.NewService(repository)
	handler := handler.NewHandler(service)


	server := new(app.Server)

	if err := server.Run(viper.GetString("8000"), handler.InitRouts() ); err != nil {
		log.Fatalf("failed to start server: %s", err.Error())
	}
}

func initConfig() error {
	viper.AddConfigPath("configs")
	viper.SetConfigName("config")
	return viper.ReadInConfig()
}