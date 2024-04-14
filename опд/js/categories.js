class Categories{
    constructor(){
        this.apiUrl = 'https://fakestoreapi.com'
    }
    getAllCategories() {
        $.ajax ({
            type: 'GET',
            url: this.apiUrl + '/products/categories',
            success: function (data){
                $(data).each(function(index, category){
                    $('.categories').append(
                        '<a class = "dropdown-item" href = "/category.html?category=' + 
                        encodeURIComponent(category) + '">' + toTitleCase(category) + "</a>"
                    )
                    
                })
            }
        })
    }
    getSingleCategory(slug){
        $.ajax ({
            type: 'GET',
            url: this.apiUrl + '/products/category/'+slug,
            success: function (data){
                $(data).each(function(index, product){
                    $('.products').append(
                        '<div class = "col-md-3"><a href = "/product.html?productid=' 
                        + product.id + '"><img src = "' + product.image 
                        + '" class = "img-fluid">' 
                        + product.title
                        + '</a></div>' 
                    )
                });
            }
        })
    }
}