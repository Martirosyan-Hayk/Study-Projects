using Authentication.Modules.User;
using Microsoft.EntityFrameworkCore;
using Authentication.Modules.Contacts;


namespace Authentication.Data
{
    public class AuthDbContext : DbContext
    {

        protected readonly IConfiguration Configuration;
        public AuthDbContext(IConfiguration configuration) /* : base(options) */
        {
            Configuration = configuration;
        }

        protected override void OnConfiguring(DbContextOptionsBuilder options)
        {
            // connect to postgres with connection string from app settings
            options.UseNpgsql(Configuration.GetConnectionString("WebApiDatabase"));
        }
        public DbSet<User> Users { get; set; }
        public DbSet<Contact> Contacts { get; set; }

    }
}