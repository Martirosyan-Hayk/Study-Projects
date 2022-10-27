using System;
using System.Threading.Tasks;
using Authentication.Data;
using Authentication.Modules;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Authentication.Controllers 
{

    [ApiController]
    [Route("api/[controller]")]
    public class UserController : Controller 
    {

        private readonly AuthDbContext _dbContext;

        public UserController(AuthDbContext dbContext)
        {
            _dbContext = dbContext;
        }

        public AuthDbContext DbContext { get; }

        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            Console.WriteLine("UserController GetAll action");

            return Ok(await _dbContext.Users.ToListAsync());
        }

        [HttpPost]
        public async Task<IActionResult> Create(AddUser addUser)
        {
            var user = new User()
            {
                Id = Guid.NewGuid(),
                Name = addUser.Name,
                Email = addUser.Email,
                Phone = addUser.Phone,
            };

            await _dbContext.Users.AddAsync(user);
            await _dbContext.SaveChangesAsync();

            return Ok(user);
        }

    }
}