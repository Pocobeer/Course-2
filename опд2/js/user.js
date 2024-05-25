class User {
    constructor() {
        this.apiLoginUrl = 'https://localhost:7034/api/User/Login';
        this.apiRegisterUrl = 'https://localhost:7034/api/User/Register';
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
            url: this.apiLoginUrl,
            data: JSON.stringify({ email: email, password: password }),
            contentType: 'application/json',
            success: (data) => {
                console.log('Ответ от сервера:', data);
                
                if (data === "Login is success") {
                    const user = { email: email };
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

    doRegister(firstName, lastName, email, password) {
        $.ajax({
            type: 'POST',
            url: this.apiRegisterUrl,
            data: JSON.stringify({email: email, password: password, firstname: firstName, lastname: lastName}),
            contentType: 'application/json',
            success: (data) => {
                console.log('Ответ от сервера:', data);
                // Предположим, что сервер возвращает объект с полем "message"
                if (data === "Register is success") {
                    window.location.href = '/login.html';
                } else {
                    $('.registrationMsg').html('<div class="alert alert-danger" role="alert">Ошибка регистрации: ' + data.message + '</div>');
                }
            },
            error: (xhr, status, error) => {
                console.error('Ошибка регистрации:', error);
                $('.registrationMsg').html('<div class="alert alert-danger" role="alert">Произошла ошибка при регистрации. Пожалуйста, попробуйте еще раз.</div>');
            }
        });
    }
}

$(document).ready(function() {
    userInfo();
});
