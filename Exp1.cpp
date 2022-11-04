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
    t1.insert(4); 
    t1.insert(5); 
    t1.insert(7); 
    t1.insert(8); 
    t1.insert(10); 
    t1.insert(11); 
    t1.insert(12); 
    t1.insert(13); 
    t1.insert(14); 
    t1.insert(15); 
    t1.insert(16); 
    t1.insert(17); 
    t1.insert(18); 

    BinarySearchTree<int> t2; // Wider and more efficient
    int NUMS = 15;
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
    clock_t start, finish;

    // Test on overall time of first tree
    start = clock();

    /*
    cout << "Links:" << endl ;
    t1.displayLinks(); 
    cout << "Height: " << endl;
    t1.height();
    cout << "Depth of Node 8: " << endl;
    t1.depth(8);*/

    for( int n = 0 ; n <= 19 ; n++ ){
        //key = (key + GAP) % CAP ;
        t1.depth( n );
    } 

    finish = clock(); 

    double overall_time1 = elapsed_time(start, finish);

    start = clock();
    t1.depth(18);
    finish = clock();

    double single_time1 = elapsed_time(start, finish);


    // Test on overall time of second tree
    start = clock();

    /*
    cout << "Links:" << endl ;
    t2.displayLinks(); 
    cout << "Height: " << endl;
    t2.height();
    cout << "Depth of Node 8: " << endl;
    t2.depth(8);*/

    for(int q = 0 ; q <= 19 ; q++ ){
        t2.depth( q );
    }      

    finish = clock();

    double overall_time2 = elapsed_time(start, finish); 

    start = clock();
    t2.depth(18);
    finish = clock();

    double single_time2 = elapsed_time(start, finish);






    // Results 
    cout << "Time taken for the first tree: " << endl;
    cout << overall_time1 << endl;
    cout << endl;

    cout << "Time taken for the second tree: " << endl;
    cout << overall_time2 << endl;
    cout << endl;

    cout << "Time taken for depth of single node in the first tree: " << endl;
    cout << single_time1 << endl;
    cout << endl;    

    cout << "Time taken for depth of single node in the second tree: " << endl;
    cout << single_time2 << endl;
    cout << endl;
}