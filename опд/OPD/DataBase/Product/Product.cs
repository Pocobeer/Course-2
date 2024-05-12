using System.ComponentModel.DataAnnotations;

namespace OPD.DataBase.Product
{
    public class Product
    {
        [Key]
        public int Id { get; set; }
        public int UserBasketId { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public decimal Price { get; set; }
        public int Quantity { get; set; }

        public Product(string name, decimal price, int quantity, string description)
        {
            Name = name;
            Price = price;
            Quantity = quantity;
            Description = description;
        }
    }
}