using System.Security.Claims;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using OPD.DataBase.Users;
using OPD.Security.JwtLogic;
using OPD.ViewModel.UsersViewModels;

namespace OPD.Controllers
{

    [ApiController]
    [Route("api/[controller]")]
    public class UserController : Controller
    {
        private readonly UserDbContext _dbContext;
        private readonly JwtService _jwtService;
        public UserController(UserDbContext dbContext, JwtService jwtService)
        {
            _dbContext = dbContext;
            _jwtService=jwtService;
        }
        [AllowAnonymous]
        [HttpPost("Register")]
        public async Task<IActionResult> RegisterUser(UserRegisterModel model)
        {
            try
            {
                return Ok(await _dbContext.RegisterUser(model));

            }
            catch (Exception ex)
            {
                return BadRequest("Server error");
            }
        }

        [AllowAnonymous]
        [HttpPost("Login")]
        public async Task<IActionResult> LoginUser([FromBody]Login login)
        {
            try
            {
                var result = await _dbContext.Login(login.Email, login.Password);
                if (result == "Login is success")
                {
                    ClaimsIdentity claims = new(new[]
                    {
                        new Claim(ClaimTypes.Email, login.Email),
                        new Claim(ClaimTypes.NameIdentifier, (await _dbContext.GetUserId(login.Email)).ToString()) // Добавление ID пользователя в claim
                    });

                    DateTime expires = DateTime.UtcNow.AddHours(1); // Установите желаемое время истечения токена

                    string token = _jwtService.GenerateToken(claims, expires);

                    // Сохранение токена в cookie
                    CookieOptions jwtCookieOptions = new()
                    {
                        Expires = expires,
                        HttpOnly = true,
                        Secure = true,
                        SameSite = SameSiteMode.None
                    };
                    Response.Cookies.Append("jwt", token, jwtCookieOptions);
                }

                return Ok(result);
            }
            catch
            {
                return BadRequest("Server error");
            }
        }

        [HttpGet("Me")]
        public async Task<IActionResult> GetMe()
        {
            try
            {
                string token = Request.Cookies["jwt"];
                return Ok(await _dbContext.GetUserFromToken(token));
            }
            catch
            {
                return BadRequest("Server error");
            }
            
        }

        [HttpPost("Delete")]
        public async Task<IActionResult> DeleteUser(int id)
        {
            await _dbContext.UserDelete(id);
            return Ok();
        }
    }
}

