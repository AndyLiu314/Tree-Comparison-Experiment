#include <iostream>
#include <time.h>
#include "BinarySearchTree.h"
using namespace std;

    double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
        return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
    } 

int main( ) {
    BinarySearchTree<int> t1; // Tall and Skinny
    t1.insert(1); 
    t1.insert(2); 
    t1.insert(5); 
    t1.insert(8); 
    t1.insert(11); 
    t1.insert(12); 
    t1.insert(14); 
    t1.insert(15); 
    t1.insert(17); 
    t1.insert(18); 

    BinarySearchTree<int> t2; // Wider and more efficient
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t2.insert( key );
    } 

    cout << "Start of Exp1" << endl;

    // Test on first tree
    clock_t start, finish;
    start = clock();

    cout << "Links:" << endl ;
    t1.displayLinks(); 
    cout << "Height: " << endl;
    t1.height();
    cout << "Depth of Node 8: " << endl;
    t1.depth(8);

    finish = clock(); 

    double overall_time1 = elapsed_time(start, finish);

    // Test on second tree
    start = clock();

    cout << "Links:" << endl ;
    t2.displayLinks(); 
    cout << "Height: " << endl;
    t2.height();
    cout << "Depth of Node 8: " << endl;
    t2.depth(8);    

    finish = clock();

    double overall_time2 = elapsed_time(start, finish); 

    // Results 
    cout << "Time taken for the first tree: " << endl;
    cout << overall_time1 << endl;
    cout << endl;

    cout << "Time taken for the second tree: " << endl;
    cout << overall_time2 << endl;
}