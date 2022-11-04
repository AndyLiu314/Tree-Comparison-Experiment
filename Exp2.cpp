#include <iostream>
#include <time.h>
#include "BinarySearchTree.h"
#include "AvlTree.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main( ) {
    AvlTree<int> a1;
    for (int l = 0; l<10; l++){
        a1.insert(l); 
    }

    a1.displayLinks();

}