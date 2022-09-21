package handler

import (
	"github.com/Martirosyan-Hayk/study-projects/Golang/pkg/service"
	"github.com/gin-gonic/gin"
)

type Handler struct {
	services *service.Service

}

func NewHandler(services *service.Service) *Handler {
	return &Handler{
		services: services,
	}
}

func (handler *Handler) InitRouts() *gin.Engine {
	router := gin.New()

	auth := router.Group("/auth")
	{
		auth.POST("/sign-up", handler.signUp)
		auth.POST("/sign-in", handler.signIn)
	}

	api := router.Group("/api")
	{
		professions := api.Group("/photos")
		{
			professions.POST("/", handler.create)
			professions.PUT("/:id", handler.update)
			professions.GET("/", handler.getAll)
			professions.GET("/:id", handler.getOne)
			professions.DELETE("/:id", handler.delete)
		}
	}

	return router
}