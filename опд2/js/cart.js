class Cart{
    constructor(){
        this.apiUrl = 'https://localhost:7034/api/Product';
    }
    getCart(userID){
        var apiUrl = this.apiUrl;
        $.ajax({
            type: 'GET',
            url: this.apiUrl + '/carts/user/' + userID,
            success: function(data){
                
                $(data).each(function(index, cart){
                    var count = 0;
                    var carts = [];
                    count += cart.products.length;
                    $(cart.products).each(function(index, products){
                        var singleProduct = {};
                        $.ajax({
                            type: 'GET',
                            url: apiUrl + '/products/' + products.productId,
                            success: function(product){
                                singleProduct['productId'] = product.id;
                                singleProduct['productUrl'] = '/product.html?productid=' + product.id;
                                singleProduct['title'] = product.title;
                                singleProduct['price'] = product.price;
                                singleProduct['image'] = product.image;
                                singleProduct['qty'] = products.quantity;
                                carts.push(singleProduct);
                                localStorage.setItem('cart', JSON.stringify(carts));

                            }
                        })
                    })
                    localStorage.setItem('cartCount', count);
                    $('span.cartCount.badge').html(count);
                })
            }
        })
    }

    getCartDisplay(products){
        var price = 0;
        $(products).each(function(index, product){
            console.log(product);
            price += product.price;
            $('.cartDisplay').prepend(
                '<a href = "' + product.productUrl +
                '"><li class="list-group-item d-flex justify-content-between lh-sm"><img src = "' 
                + product.image + '"class = "img-thumbnail" style = "max-width: 50px;"><div><h6>'+ 
                product.title + '</h6></div><span class="text-body-secondary">' 
                + product.price.toFixed(2) + '</span></li></a> '
            )
        });
        $('.price').html(price);
        /*<li class="list-group-item d-flex justify-content-between lh-sm">
            <div>
                <h6 class="my-0">Product name</h6>
                <small class="text-body-secondary">Brief description</small>
            </div>
            <span class="text-body-secondary">$12</span>
        </li> */
    }
}