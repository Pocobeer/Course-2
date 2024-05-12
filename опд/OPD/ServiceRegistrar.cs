using System.Text;
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;

using OPD.DataBase;
using OPD.DataBase.Users;
using OPD.Security.JwtLogic;

namespace OPD
{
    public static class ServiceRegistrar
    {
        public static void Register(IServiceCollection serviceCollection)
        {

            serviceCollection.AddDbContext<ApplicationDbContext>();
            serviceCollection.AddScoped<UserDbContext>();
            serviceCollection.AddCors(options =>
            {
                options.AddPolicy("AllowAllOrigins",
                    builder =>
                    {
                        builder.AllowAnyOrigin()
                            .AllowAnyMethod()
                            .AllowAnyHeader();
                    });
            });
            serviceCollection.AddControllers();
            serviceCollection.AddSingleton(provider =>
            {
                IConfiguration config = provider.GetRequiredService<IConfiguration>();
                return config.GetValue<string>(JwtOptions.SecretKey);
            });
            serviceCollection.AddScoped<JwtService>();
            serviceCollection.AddAuthentication(options =>
                {
                    options.DefaultAuthenticateScheme = JwtBearerDefaults.AuthenticationScheme;
                    options.DefaultChallengeScheme = JwtBearerDefaults.AuthenticationScheme;
                })
                .AddJwtBearer(options =>
                {
                    options.TokenValidationParameters = new TokenValidationParameters
                    {
                        ValidateIssuerSigningKey = true,
                        IssuerSigningKey = new SymmetricSecurityKey(Encoding.ASCII.GetBytes(JwtOptions.SecretKey)),
                        ValidateIssuer = true,
                        ValidIssuer = JwtOptions.Issuer,
                        ValidateAudience = true,
                        ValidAudience = JwtOptions.Audience,
                        ValidateLifetime = true,
                        ClockSkew = TimeSpan.Zero
                    };
                });
        }
    }
}
