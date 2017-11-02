#include "Product.h"
#include <string.h>

namespace Product
{
  Product::Product(int _q, int _p, std::string _n)
  {
    quantity = _q;
    price = _p;
    name = _n;
    std::cout << "A product " << name << " has been created." << std::endl;
  }
  Product::~Product()
  {
    std::cout << "A product " << name << " has been deleted" << std::endl;
  }
  void Product::PrintProductInfo()
  {
    std::cout << Product::name << " " << Product::price << " " << Product::quantity << std::endl;
  }
  int Product::GetPrice()
  {
    return Product::price;
  }
  int Product::GetQuantity()
  {
    return Product::quantity;
  }
  std::string Product::GetName()
  {
    return Product::name;
  }


  bool operator <(Product &p1, Product &p2)
  {
    return p1.GetPrice() < p2.GetPrice();
  }
  bool operator <=(Product &p1, Product &p2)
  {
    return p1.GetPrice() <= p2.GetPrice();
  }
  bool operator >(Product &p1, Product &p2)
  {
    return p1.GetPrice() > p2.GetPrice();
  }
  bool operator >=(Product &p1, Product &p2)
  {
    return p1.GetPrice() >= p2.GetPrice();
  }
  bool operator ==(Product &p1, Product &p2)
  {
    return !(p1.GetName()).compare(p2.GetName());
  }

  ProductList::ProductList()
  {
    ProductList::products = std::vector<Product*>();
    std::cout << "A product list has been created." << std::endl;
  }
  ProductList::~ProductList()
  {
    while (ProductList::products.size()>0)
    {
		//Deleting all products whose references were stored in the list
      delete ProductList::products.back();
      ProductList::products.pop_back();
    }
    ProductList::products.clear();
    std::cout << "A product list has been deleted." <<std::endl;
  }
  void ProductList::AddProduct(int _q, int _p, std::string _n)
  {
    ProductList::products.push_back(new Product(_q, _p, _n));
  }

  void ProductList::DeleteProductAt(int index)
  {
    if (index<0 || index>=ProductList::products.size())
    {
      std::cout << "Not a valid index!";
      return;
    }
    delete ProductList::products[index];
    ProductList::products.erase(ProductList::products.begin() + index);
    std::cout << "A product has been erased."<< std::endl;
  }
  void ProductList::PrintAllProducts()
  {
    for (int i=0; i < ProductList::products.size(); i++)
    {
      std::cout << i << ". ";
      ProductList::products[i]->PrintProductInfo();
    }
  }
  int ProductList::GetSize() {return products.size();}

  Product* ProductList::GetProductAt(int i) 
  {
	  return products[i];
	}

  void ProductList::operator +=(ProductList& list)
  {
    for (int i = 0; i < list.products.size(); i++)
    {
		//Checking, if this produc isn' already present in the list. (No duplicates)
      if (!(this->isIn(list.products[i])))
      {
		  //If not, copy the object from the given list.
        ProductList::products.push_back(new Product(list.products[i]->GetQuantity(), list.products[i]->GetPrice(), list.products[i]->GetName()));
      }

    }

  }
  Product* ProductList::FindMostExpensive()
  {
    if (ProductList::products.size() == 0) return NULL;
    Product* toRet;
    
    toRet = ProductList::products[0];
    
    for (int i=0; i<ProductList::products.size(); i++)
      {
        if ((toRet) <= (ProductList::products[i]))
          toRet = ProductList::products[i];
      }
      return toRet;
  }
  Product* ProductList::FindCheapest()
  {
    if (ProductList::products.size() == 0) return NULL;
    Product* toRet;
    
    toRet = ProductList::products[0];
    
    for (int i=0; i<ProductList::products.size(); i++)
      {
        if ((toRet) >= (ProductList::products[i]))
          toRet = ProductList::products[i];
      }
      return toRet;
  }

  bool ProductList::isIn(Product* p)
  {
    for (int i = 0; i < products.size(); i++)
    {
      if (*p == *products[i])
        return true;
    }
    return false;
  }

  ProductList* operator +(ProductList& list1, ProductList& list2)
  {
    ProductList *toRet;
    toRet = new ProductList();
    for (int i = 0; i < list1.GetSize(); i++)
    {
        toRet->AddProduct(list1.GetProductAt(i)->GetQuantity(), list1.GetProductAt(i)->GetPrice(), list1.GetProductAt(i)->GetName());
    }
    for (int j = 0; j < list2.GetSize(); j++)
    {
      if (!toRet->isIn(list2.GetProductAt(j)))
      {
		  //Checking, if this produc isn' already present in the list. (No duplicates)
        toRet->AddProduct(list2.GetProductAt(j)->GetQuantity(), list2.GetProductAt(j)->GetPrice(), list2.GetProductAt(j)->GetName());
      }
    }
    return toRet;
  };
}
