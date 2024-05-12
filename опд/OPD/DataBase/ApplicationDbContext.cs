using Microsoft.EntityFrameworkCore;
using OPD.DataBase.Product;
using OPD.DataBase.Users;

namespace OPD.DataBase
{
    public class ApplicationDbContext : DbContext
    {

        //Создание таблиц
        public DbSet<User> Users { get; set; }
        public DbSet<UserBasket> Baskets { get; set; }
        public DbSet<Product.Product> Products { get; set; }

        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options) : base(options)
        {
            //создание базы данных если ее нет, после создания необходимо закомментировать
            Database.EnsureCreated();

        }

        protected override void OnConfiguring(DbContextOptionsBuilder builder)
        {
            builder.UseNpgsql("Host=localhost;Port=5432;Database=OnlineShop;Username=postgres;Password=63403;Include Error Detail=true;");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>()
                .HasOne(u => u.UserBasket)
                .WithOne()
                .HasForeignKey<UserBasket>(ub => ub.UserId);
            modelBuilder.Entity<UserBasket>()
                .HasMany(b => b.Products)
                .WithOne()
                .HasForeignKey(p => p.UserBasketId);
        }

    }

}
