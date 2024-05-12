using System.ComponentModel.DataAnnotations;

namespace OPD.DataBase.Product
{
    public class UserBasket
    {
        [Key]
        public int Id { get; set; }
        public int UserId { get; set; }
        public List<Product> Products { get; set; }

        public UserBasket()
        {
            Products = new List<Product>();
        }
    }

}
