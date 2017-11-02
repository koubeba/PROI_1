#include <iostream>
#include <stdlib.h>
#include <vector>

#ifndef PRODUCT_H
#define PRODUCT_H
namespace Product
{
  class Product
  {
    int quantity;
    int price;
    int id;
    std::string name;

  public:
    Product(int _q, int _p, std::string _n);
    ~Product();
    void PrintProductInfo();
    int GetPrice();
    int GetQuantity();
    std::string GetName();
  };

  bool operator <(Product p1, Product p2);
  bool operator <=(Product p1, Product p2);
  bool operator >(Product p1, Product p2);
  bool operator >=(Product p1, Product p2);
  bool operator ==(Product p1, Product*p2);

  class ProductList
  {
    std::vector<Product*> products;

  public:
    ProductList();
    ~ProductList();
    void AddProduct(int _q, int _p, std::string _n);

    void DeleteProductAt(int index);
    void PrintAllProducts();
    int GetSize();
    Product* GetProductAt(int i);
    void operator +=(ProductList& list);
    Product* FindMostExpensive();
    Product* FindCheapest();
    bool isIn(Product* p);
  };
  ProductList* operator +(ProductList& list1, ProductList& list2);
}
#endif
