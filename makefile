Shopping: Product.o Test.o
	g++ -o Shopping Product.o Test.o

Product.o: Product.h Product.cpp
	g++ -c Product.cpp

Test.o: Test.h Test.cpp
	g++ -c Test.cpp
