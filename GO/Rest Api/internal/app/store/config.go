package store

type Config struct {
	DatabaseURL string `toml:"database_url"`
}

func NewConfig() *Config {
	return &Config{
		DatabaseURL: "postgres://postgres:postgres@localhost:5432/postgres?sslmode=disable",
	}
}