using Microsoft.EntityFrameworkCore;
using Authentication.Modules;

namespace Authentication.Data {
    public class AuthDbContext : DbContext{

        public AuthDbContext(DbContextOptions options) : base(options)
        {

        }

        public DbSet<User> Users { get; set; }

    }
}