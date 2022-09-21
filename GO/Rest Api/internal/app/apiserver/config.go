package apiserver

import "github.com/Martirosyan-Hayk/study-projects/Go/internal/app/store"

type Config struct {
	BindAddr string `toml:"bind_addr"`
	LogLevel string `toml:"log_level"`
	Store   *store.Config `toml:"store"`
}

func NewConfig() *Config {
	return &Config{
		BindAddr: ":8080",
		LogLevel: "debug",
		Store: store.NewConfig(), 
	}
}