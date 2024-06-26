$(function() {
    if(localStorage.user == null && $('.auth').length){
        //window.location.href = '/logout.html';
    }
    
    loadScript('js/categories.js', categoriesSetup);
    loadScript('js/products.js', productsSetup);
    loadScript('js/user.js', userInfo);
    loadScript('js/cart.js', cartInfo);
})

$.get('/templates/navigation.html', function(data) {
    if($('.logout').length){
        localStorage.clear();
    }
    $('#nav-placeholder').replaceWith(data)
    if(localStorage.user == null){
        $('.accountNav').html('<li class = "nav-item"><a class = "nav-link text-white" href = "/login.html">Войти</a></li>')
    }else{
        $('.accountNav').html('<li class = "nav-item"><a class = "nav-link text-white" href = "/logout.html">Выйти</a></li><li class = "nav-item"><a class = "nav-link text-white" href = "/account.html">Личный кабинет</a></li>')
    }
})

$.get('/templates/footer.html', function(data) {
    $('#footer-placeholder').replaceWith(data)
})




var categoriesSetup = function() {
    let categories = new Categories();
    categories.getAllCategories();
    if(urlParam('category')){
        categories.getSingleCategory(decodeURIComponent(urlParam('category')));
    }
}
var productsSetup = function() {
    let products = new Products();
    if($('.products.new').length){
        products.getNewProducts(8);
    }
    if (urlParam('productid')){
        products.getSingleProduct(urlParam('productid'));
    }
}

var userInfo = function() {
    let user = new User();
    $('form.login').submit(function(e){
        e.preventDefault();
        var email = $('#email').val();
        var password = $('#password').val();
        user.doLogin(email, password);
    })
    if ($('.userAccount').length){
        var userAccount = JSON.parse(localStorage.user);
        user.getAccountInfo(userAccount);
    }
}

var cartInfo = function(){
    let cart = new Cart();
    if(localStorage.user != null){
        var user = JSON.parse(localStorage.user);
        cart.getCart(user.id);
        if(localStorage.getItem('cartCount') != 0){
            var cartItems = JSON.parse(localStorage.cart);
            cart.getCartDisplay(cartItems);
        }
    }
}
function loadScript(url, callback) {
    var head = document.head
    var script = document.createElement('script')
    script.type = 'text/javascript'
    script.src = url
    script.onreadystatechange = callback
    script.onload = callback
    head.appendChild(script) 
}

function toTitleCase(str){
    return str.replace(/(?:^|\s)\w/g, function(match) {
        return match.toUpperCase();
    })
}

function urlParam(name){
    var results = new RegExp("[?&]" + name 
    + "=([^&#]*)").exec(window.location.href);
    if(results==null){
        return null;
    }
    else{
        return results[1] || 0;
    }
}