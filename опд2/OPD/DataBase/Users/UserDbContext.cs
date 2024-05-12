using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Security.Cryptography;
using System.Text;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using OPD.Security.JwtLogic;
using OPD.ViewModel.UsersViewModels;

namespace OPD.DataBase.Users
{
    public class UserDbContext
    {
        private readonly ApplicationDbContext _dbContext;
        public UserDbContext(ApplicationDbContext dbContext)
        {
            _dbContext = dbContext;
        }
        public async Task<string> RegisterUser(UserRegisterModel model)
        {
            if ((await GetUserByEmail(model.Email)) != null)
            {
                return "The user with this Email has already been registered";
            }
            await _dbContext.Users.AddAsync(
                new User(
                    model.FirstName,
                    model.LastName,
                    model.Email,
                    GeneratePasswordHash(model.Password)
                    )
                );
            await _dbContext.SaveChangesAsync();
            return "Register is success";
        }

        public async Task<string> Login(string email, string password)
        {
            var user = await GetUserByEmail(email);
            if (user == null)
            {
                return "User not found";
            }

            if (GeneratePasswordHash(password) == user.Password)
            {
                return "Login is success";
            }
            return "Invalid Password";
        }

        public async Task<User> GetUserByEmail(string email)
        {
            return await _dbContext.Users
                .FirstOrDefaultAsync(u => u.Email == email);
        }

        public async Task<int> GetUserId(string email)
        {
            var user = await GetUserByEmail(email);
            return user.Id;
        }

        public async Task<User> GetUserById(int id)
        {
            return await _dbContext.Users.FirstOrDefaultAsync(x => x.Id == id);
        }

        public async Task<User> GetUserFromToken(string token)
        {
            JwtSecurityTokenHandler tokenHandler = new JwtSecurityTokenHandler();
            TokenValidationParameters tokenValidationParameters = new TokenValidationParameters
            {
                ValidateIssuer = true,
                ValidateAudience = true,
                ValidateLifetime = true,
                ValidateIssuerSigningKey = true,
                ValidIssuer = JwtOptions.Issuer,
                ValidAudience = JwtOptions.Audience,
                IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(JwtOptions.SecretKey))
            };

            SecurityToken securityToken;
            ClaimsPrincipal principal = tokenHandler.ValidateToken(token, tokenValidationParameters, out securityToken);
            string userId = principal.FindFirst(ClaimTypes.NameIdentifier).Value;
            return await GetUserById(int.Parse(userId));
        }

        public async Task UserDelete(int id)
        {
            var user = await _dbContext.Users.FirstOrDefaultAsync(x => x.Id == id);
            _dbContext.Remove(user);
            await _dbContext.SaveChangesAsync();
            
        }
        private string GeneratePasswordHash(string password)
        {
            using SHA256 sha256 = SHA256.Create();
            byte[] passwordBytes = Encoding.UTF8.GetBytes(password);
            byte[] hashBytes = sha256.ComputeHash(passwordBytes);
            return Convert.ToBase64String(hashBytes);
        }
    }
}
