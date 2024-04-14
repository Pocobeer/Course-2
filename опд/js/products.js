class Products{
    constructor(){
        this.apiUrl = 'https://fakestoreapi.com'
    }
    getSingleProduct(id){
        $.ajax ({
            type: 'GET',
            url: this.apiUrl + '/products/' + id,
            success: function (data){
                console.log(data);
                $('.product_image').html('<img src = "' + data.image + '"class = "img-fluid">')
                $('.product_title').html(data.title)
                $('.product_price').html('$' + data.price.toFixed(2))
                $('.product_description').html('<p>' + data.description + '</p>')
            }
        })
    }
}