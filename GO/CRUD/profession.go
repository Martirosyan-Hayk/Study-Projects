package app

type Profession struct {
	Id  int `json:"-"`
	Title string `json:"title"`
	Description string `json:"description"`
}


type UserProfession struct {
	Id  int 
	UserId int 
	ProfessionId int 
}
