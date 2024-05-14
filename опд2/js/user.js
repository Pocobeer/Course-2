class User {
    constructor() {
        this.apiUrl = 'https://fakestoreapi.com';
    }

    getAccountInfo() {
        const storedUser = JSON.parse(localStorage.getItem('user'));
        if (storedUser) {
            console.log(storedUser);
            $('#username').val(storedUser.username);
            $('#fname').val(storedUser.name.firstname);
            $('#lname').val(storedUser.name.lastname);
            $('#phone').val(storedUser.phone);
            $('#email_user').val(storedUser.email);
            $('#address').val(storedUser.address.number + ' ' + storedUser.address.street);
            $('#city').val(storedUser.address.city);
            $('#zip').val(storedUser.address.zipcode);
        } else {
            console.error('Ошибка: Пользователь не найден в локальном хранилище.');
        }
    }

    doLogin(email, password) {
        console.log('Email:', email);
        console.log('Password:', password);
        localStorage.clear();
        $.ajax({
            type: 'GET',
            url: this.apiUrl + '/users',
            success: function(data) {
                console.log(data);
                $(data).each(function(index, user) {
                    if (user.email == email && user.password == password) {
                        localStorage.setItem('user', JSON.stringify(user));
                    }
                });
                if (localStorage.getItem('user') != null) {
                    window.location.href = '/index.html';
                } else {
                    // $('.loginMsg').html('<div class = "alert alert-danger role = "alert">Неправильное имя пользователя или пароль</div>');
                }
            },
        });
    }
}
