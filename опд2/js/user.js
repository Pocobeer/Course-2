class User {
    constructor() {
        this.apiUrl = 'https://localhost:7034/api/User/Login';
    }

    getAccountInfo() {
        const storedUser = JSON.parse(localStorage.getItem('user'));
        if (storedUser) {
            console.log(storedUser);
            $('#fname').val(storedUser.name.firstname);
            $('#lname').val(storedUser.name.lastname);
            $('#email_user').val(storedUser.email);
        } else {
            console.error('Ошибка: Пользователь не найден в локальном хранилище.');
        }
    }

    doLogin(email, password) {
        console.log('Email:', email);
        console.log('Password:', password);
        localStorage.clear();

        $.ajax({
            type: 'POST',
            url: this.apiUrl,
            data: JSON.stringify({ email: email, password: password }),
            contentType: 'application/json',
            success: (data) => {
                console.log('Ответ от сервера:', data);
                
                // Проверка успешного логина на основе ответа сервера
                if (data === "Login is success") {
                    // Сохранение информации о пользователе в локальное хранилище (дополнительно)
                    const user = { email: email }; // Предположим, что у нас есть только email для сохранения
                    localStorage.setItem('user', JSON.stringify(user));
                    window.location.href = '/index.html';
                } else {
                    $('.loginMsg').html('<div class="alert alert-danger" role="alert">Неправильное имя пользователя или пароль</div>');
                }
            },
            error: (xhr, status, error) => {
                console.error('Ошибка входа:', error);
                $('.loginMsg').html('<div class="alert alert-danger" role="alert">Произошла ошибка при входе. Пожалуйста, попробуйте еще раз.</div>');
            }
        });
    }
}

$(document).ready(function() {
    userInfo();
});