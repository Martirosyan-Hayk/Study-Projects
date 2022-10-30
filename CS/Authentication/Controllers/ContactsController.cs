using System;
using System.Threading.Tasks;
using Authentication.Data;
using Authentication.Modules.Contacts;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace Authentication.Controllers
{

    [ApiController]
    [Route("api/[controller]")]
    public class ContactsController : Controller
    {

        private readonly AuthDbContext _dbContext;

        public ContactsController(AuthDbContext dbContext)
        {
            _dbContext = dbContext;
        }

        public AuthDbContext DbContext { get; }

        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            return Ok(await _dbContext.Contacts.ToListAsync());
        }

        [HttpPost]
        public async Task<IActionResult> Create(AddContact addContact)
        {
            var contact = new Contact()
            {
                Id = Guid.NewGuid(),
                FullName = addContact.FullName,
                Email = addContact.Email,
                Phone = addContact.Phone,
                Address = addContact.Address,
            };

            await _dbContext.Contacts.AddAsync(contact);
            await _dbContext.SaveChangesAsync();

            return Ok(contact);
        }

    }
}