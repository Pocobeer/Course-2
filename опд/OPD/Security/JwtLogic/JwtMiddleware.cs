namespace OPD.Security.JwtLogic
{
    public class JwtMiddleware
    {
        private readonly RequestDelegate _next;

        public JwtMiddleware(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext context, JwtService _jwtService)
        {
            string path = context.Request.Path.Value.ToLower();
            if (path.StartsWith("/swagger") || context.Request.Method == "OPTIONS" || context.Request.Method == "HEAD")
            {
                await _next(context);
                return;
            }

            string token = context.Request.Cookies["jwt"];
            if (!string.IsNullOrEmpty(token))
            {
                System.Security.Claims.ClaimsPrincipal principal = _jwtService.ValidateToken(token);

                if (principal != null)
                {
                    // Устанавливаем пользователя в контекст
                    context.User = principal;
                }
            }

            await _next(context); // Перемещаем вызов _next(context) в конец метода
        }

    }
}
