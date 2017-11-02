#include <string>
#include <climits>
#include "Product.h"

enum inputType {text, number};

void showInstruction();
void printAllLists();
void input(int* number, std::string numberName = "number", int min = INT_MIN, int max = INT_MAX);
void input(std::string* str, std::string strName = "name");
