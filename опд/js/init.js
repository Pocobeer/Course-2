$.get('/templates/navigation.html', function(data) {
    $('#nav-placeholder').replaceWith(data)
})

$.get('/templates/footer.html', function(data) {
    $('#footer-placeholder').replaceWith(data)
})

// document.querySelector("show-login").addEventListener("click", function() {
//     document.querySelector(".popup").classList.add("active");
// });

// document.querySelector(".popup .close-btn").addEventListener("click", function() {
//     document.querySelector(".popup").classList.remove("active");
// });

$(function() {
    loadScript('js/categories.js', categoriesSetup);
    loadScript('js/products.js', productsSetup);
    loadScript('js/user.js', userInfo);

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
    user.getUserInfo();
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