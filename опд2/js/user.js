class User{
    constructor(){
        this.apiUrl = 'https://fakestoreapi.com'
    }

    getAccountInfo(user){
        console.log(user);
        $('#username').val(user.username);
        $('#fname').val(user.name.firstname);
        $('#lname').val(user.name.lastname);
        $('#phone').val(user.phone);
        $('#email_user').val(user.email);
        $('#address').val(user.address.number + ' ' + user.address.street);
        $('#city').val(user.address.city);
        $('#zip').val(user.address.zipcode);
    }
    doLogin(email, password){
        console.log('Email:', email);
        console.log('Password:', password);
        localStorage.clear();
        $.ajax({
            type: 'GET',
            url: this.apiUrl + '/users',
            success: function(data){
                console.log(data);
                $(data).each(function(index, user){
                    if(user.email == email && user.password == password){
                        localStorage.setItem('user', JSON.stringify(user));
                    }
                });
                if(localStorage.getItem('user') != null){
                    window.location.href = '/index.html';
                }else{
                   // $('.loginMsg').html('<div class = "alert alert-danger role = "alert">Неправильное имя пользователя или пароль</div>');
                }
            },
        });
    }
}