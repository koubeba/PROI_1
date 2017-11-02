#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <climits>
#include "Product.h"

void showInstruction()
{
	std::cout << "\ta. Add a product list" << std::endl;
	std::cout << "\tb. Add a product to existing list" << std::endl;
	std::cout << "\tc. Show all lists" << std::endl;
	std::cout << "\td. Show all products in an existing list" << std::endl;
	std::cout << "\te. Delete a product from list" << std::endl;
	std::cout << "\tf. Delete a list" << std::endl;
	std::cout << "\tg. Add products from one list to another list" << std::endl;
	std::cout << "\th. Sum two lists" << std::endl;
	std::cout << "\ti. Show most expensive element" << std::endl;
	std::cout << "\tj. Show the cheapest element" << std::endl;
    std::cout << "\tk. Run automatic tests" << std::endl;
    std::cout << "\tl. Show instruction" << std::endl;
	std::cout << "\tq. Exit\n" << std::endl;
}

void printAllLists(std::vector<Product::ProductList*> lists)
{
	for (int i = 0; i< lists.size(); i++)
	{
		std::cout << i << ". No of elements: " << lists[i]->GetSize() << std::endl;
	}
}

void input(int* number, std::string numberName = "number", int min = INT_MIN, int max = INT_MAX)
{
    //Checking: is the given pointer not null
    if (number)
    {
        //Checking: is the entered data the right type (int)
        while ((std::cout << "Enter a " + numberName + ": ") && !(std::cin >> *number))
        {
            //Clearing the input after receiving wrong data.
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "ERROR: Wrong input type. Please enter a number." << std::endl;
        }
        //Checking: is the entered number in right range.
        if (min != INT_MIN)
        {
            if (*number < min)
            {
                std::cout << "ERROR: Number too small. Please enter a number bigger than " << (min-1) << " and smaller than " << (max+1) << std::endl;
                input(number, numberName, min, max);
            }
        }
        if (max != INT_MAX)
        {
            if (*number > max)
            {
                std::cout << "ERROR: Number too big. Please enter a number bigger than " << (min-1) << " and smaller than " << (max+1) << std::endl;
                input(number, numberName, min, max);
            }
        }
    }
}
void input(std::string* str, std::string strName = "name")
{
    //Checking: is the given pointer not null
    if (str)
    {
        //Checking: is the entered data the right type (std::string)
        while ((std::cout << "Enter a " + strName + ": ") && !(std::cin >> *str))
        {
            //Clearing the input after receiving wrong data.
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Wrong input.";
        }
    }
}


int main()
{
  std::vector<Product::ProductList*> lists = std::vector<Product::ProductList*>();
  char c;
  int index, listIndex, q, p;
  std::string name;
  showInstruction();
  do
  {
	  std::cout << "A letter, please: ";
	  std::cin >> c;
	  switch (c)
	  {
		  case 'A':
		  case 'a':
              //Create a new, empty list
			lists.push_back(new Product::ProductList());
		  break;
		  case 'b':
          case 'B':
              //Checking: If there are no lists, there is nothing to add a product to.
			if (lists.size()<=0)
				{
					std::cout << "ERROR: No lists " << std::endl;
					break;
				}
              //UI: Printing all list so the user can choose index of a list.
			printAllLists(lists);
			std::cout << "Select a list to add a product to." << std::endl;

              //Reading user input.
              input(&index, "list index", 0, lists.size()-1);
			input(&q, "product quantity", 0);
              input(&p, "product price", 0);
              input(&name, "product name");

              //Creating a new product and adding it to list.
			lists[index]->AddProduct(q, p, name);
		  break;
		  case 'C':
		  case 'c':
			printAllLists(lists);
		  break;
		  case 'D':
		  case 'd':
              //Checking: If there are no lists, there is nothing to show.
		  if (lists.size()<=0)
				{
					std::cout << "ERROR: No lists " << std::endl;
					break;
				}
				//UI: Showing all products of a list.
				printAllLists(lists);
			std::cout << "Select a list and show all its products." << std::endl;

              //Reading user input.
              input(&index, "list index", 0, lists.size()-1);

			lists[index]->PrintAllProducts();
		  break;
		  case 'E':
		  case 'e':
              //Checking: If there are no lists, there is nothing to delete.
		  if (lists.size()<=0)
				{
					std::cout << "No lists " << std::endl;
					break;
				}
			std::cout << "Select a list to delete a product from." << std::endl;
				//UI: Showing all products of a list.
				printAllLists(lists);
              //Reading user input.
              input(&index, "list index", 0, lists.size()-1);

			std::cout << "Select index of an element to delete." << std::endl;
				//UI: Showing all products of a list.
				lists[index]->PrintAllProducts();
              //Reading user input.
              if(lists[index]->GetSize()==0)
				{
					std::cout << "A list is empty!" << std::endl;
					break;
				}
              input(&listIndex, "product index", 0, lists[index]->GetSize()-1);
			lists[index]->DeleteProductAt(listIndex);
		  break;
		  case 'F':
		  case 'f':
              //Checking: If there are no lists, there is nothing to delete.
		  if (lists.size()<=0)
				{
					std::cout << "No lists " << std::endl;
					break;
				}
			std::cout << "Select a list to delete." << std::endl;

              //Reading user input.
              input(&index, "list index", 0, lists.size()-1);
			delete lists[index];
			lists.erase(lists.begin() + index);
		  break;
		  case 'G':
          case 'g':
              //Checking: if there is one or less lists, there is nothing to sum.
		  if (lists.size()<=1)
				{
					std::cout << "Insufficient number of lists" << std::endl;
					break;
				}
			std::cout << "Select a list to which we will add." << std::endl;

              //Reading user input.
              input(&index, "first list index", 0, lists.size()-1);

			std::cout << "Select a list which products we will add." << std::endl;

              //Reading user input.
              input(&listIndex, "second list index", 0, lists.size()-1);

			*lists[index] += *lists[listIndex];
		  break;
		  case 'H':
		  case 'h':
              //Checking: if there is one or less lists, there is nothing to sum.
              if (lists.size()<=1)
              {
                  std::cout << "Insufficient number of lists" << std::endl;
                  break;
              }
			//lists.push_back(new Product::ProductList());
			std::cout << "Select two lists to sum." << std::endl;
              //Reading user input.
              input(&index, "first list index", 0, lists.size()-1);
              input(&listIndex, "second list index", 0, lists.size()-1);

			lists.push_back(*lists[index] + *lists[listIndex]);
		  break;
		  case 'I':
          case 'i':
              //Checking: If there are no lists, there is nothing to show.
              if (lists.size()<=0)
              {
                  std::cout << "No lists " << std::endl;
                  break;
              }

              std::cout << "Select a list to show its most expensive element." << std::endl;

              //Reading user input.
              input(&index, "list index", 0, lists.size()-1);

			lists[index]->FindMostExpensive()->PrintProductInfo();
		  break;
		  case 'J':
		  case 'j':
              //Checking: If there are no lists, there is nothing to show.
              if (lists.size()<=0)
              {
                  std::cout << "No lists " << std::endl;
                  break;
              }

              std::cout << "Select a list to show its most expensive element." << std::endl;

              //Reading user input.
              input(&index, "list index", 0, lists.size()-1);

			lists[index]->FindCheapest()->PrintProductInfo();
		  break;
          case 'K':
          case 'k':
              //Testing creating lists:
          std::cout << "TESTING: Creating and adding 2 new lists." << std::endl << std::endl;
              lists.push_back(new Product::ProductList());
              lists.push_back(new Product::ProductList());

              printAllLists(lists);

          std::cout << std::endl << "TESTING: Adding new products." << std::endl << std::endl;
              std::cout <<  "ADDING product DOG to list 0." << std::endl ;
              lists[lists.size()-2]->AddProduct(10, 20, "DOG");
              std::cout <<  "ADDING product CAT to list 0." << std::endl ;
              lists[lists.size()-2]->AddProduct(20, 30, "CAT");
              std::cout <<  "ADDING product ORE to list 0." << std::endl ;
              lists[lists.size()-2]->AddProduct(20, 60, "ORE");
              std::cout <<  "ADDING product DOG to list 1." << std::endl ;
              lists[lists.size()-1]->AddProduct(10, 30, "DOG");
              std::cout <<  "ADDING product FLY to list 1." << std::endl ;
              lists[lists.size()-1]->AddProduct(100, 5, "FLY");

              printAllLists(lists);

              std::cout << std::endl << "TESTING: Printing all elements of list 0 and 1." << std::endl << std::endl;

              lists[lists.size()-2]->PrintAllProducts();
              lists[lists.size()-1]->PrintAllProducts();

              std::cout << std::endl << "TESTING: Adding elements from list 1 to list 0 (+= operator)." << std::endl << std::endl;

              *lists[lists.size()-2] += *lists[lists.size()-1];
              lists[lists.size()-2]->PrintAllProducts();
              lists[lists.size()-1]->PrintAllProducts();

              std::cout << std::endl << "TESTING: Creating a sum of list 0 and 1 (+ operator)." << std::endl << std::endl;

              lists.push_back(*lists[lists.size()-2] + *lists[lists.size()-1]);
              lists[lists.size()-1]->PrintAllProducts();

              std::cout << std::endl << "TESTING: Deleting product no. 0 of list 0." << std::endl << std::endl;
              lists[lists.size()-3]->DeleteProductAt(0);
              lists[lists.size()-3]->PrintAllProducts();
              lists[lists.size()-2]->PrintAllProducts();
              lists[lists.size()-1]->PrintAllProducts();

              std::cout << std::endl << "TESTING: Finding the most expensive element of list 2." << std::endl << std::endl;
              lists[lists.size()-1]->FindMostExpensive()->PrintProductInfo();

              std::cout << std::endl << "TESTING: Finding the cheapest element of list 2." << std::endl << std::endl;
              lists[lists.size()-1]->FindCheapest()->PrintProductInfo();


              break;
          case 'L':
          case 'l':
              showInstruction();
              break;

	  }
  }while(c!='q');
  

  return 0;
}
