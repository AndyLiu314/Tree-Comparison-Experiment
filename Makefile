all: BSTtest BSTtest2

BSTtest: BSTtest.o  # test program for BinarySearchTree class
	g++ -Wall -o BSTtest BSTtest.o  

BSTtest2: BSTtest2.o  # test program for BinarySearchTree class
	g++ -Wall -o BSTtest2 BSTtest2.o  

BSTtest.o: BSTtest.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o BSTtest.o -c BSTtest.cpp 

BSTtest2.o: BSTtest2.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o BSTtest2.o -c BSTtest2.cpp 

clean:
	rm -f BSTtest2 BSTtest2 *.o