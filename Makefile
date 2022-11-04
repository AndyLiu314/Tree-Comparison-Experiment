all: BSTtest BSTtest2 DLtest Htest Dtest Exp1 Exp2

BSTtest: BSTtest.o  # test program for BinarySearchTree class
	g++ -Wall -o BSTtest BSTtest.o  

BSTtest2: BSTtest2.o  # test program for BinarySearchTree class
	g++ -Wall -o BSTtest2 BSTtest2.o  

DLtest: DLtest.o  # test program for BinarySearchTree class
	g++ -Wall -o DLtest DLtest.o

Htest: Htest.o  # test program for BinarySearchTree class
	g++ -Wall -o Htest Htest.o

Dtest: Dtest.o  # test program for BinarySearchTree class
	g++ -Wall -o Dtest Dtest.o

Exp1: Exp1.o  # test program for BinarySearchTree class
	g++ -Wall -o Exp1 Exp1.o

Exp2: Exp2.o  # test program for BinarySearchTree and Avl class
	g++ -Wall -o Exp2 Exp2.o

BSTtest.o: BSTtest.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o BSTtest.o -c BSTtest.cpp 

BSTtest2.o: BSTtest2.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o BSTtest2.o -c BSTtest2.cpp 

DLtest.o: DLtest.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
	g++ -Wall -o DLtest.o -c DLtest.cpp 

Htest.o: Htest.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
	g++ -Wall -o Htest.o -c Htest.cpp 

Dtest.o: Dtest.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
	g++ -Wall -o Dtest.o -c Dtest.cpp 

Exp1.o: Exp1.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o Exp1.o -c Exp1.cpp 

Exp2.o: Exp2.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
	g++ -Wall -o Exp2.o -c Exp2.cpp 

clean:
	rm -f BSTtest BSTtest2 DLtest Htest Dtest Exp1 Exp2 *.o
