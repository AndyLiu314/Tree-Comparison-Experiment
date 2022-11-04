#include <iostream>
#include <time.h>
#include "BinarySearchTree.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main( ) {
    BinarySearchTree<int> t1; // Tall and Skinny
    for (int l = 0; l<10000; l++){
        t1.insert(l); 
    }

    BinarySearchTree<int> t2; // Wider and more efficient
    int NUMS = 10000;
    const int GAP  = 3 ;
    const int CAP  = 10000;
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
    for( int n = 0 ; n < 10000 ; n++ ){
        t1.depth( n );
    } 
    finish = clock(); 
    double overall_time1 = elapsed_time(start, finish);

    // Finding average search time for first tree
    double avgtime1 = 0;
    for( int j = 0 ; j < 10000 ; j++ ){
        start = clock();
        t1.depth( j );
        finish = clock();

        avgtime1 += elapsed_time(start, finish);
    } 
    avgtime1 = avgtime1/10000;

    // Finding average search depth for first tree
    int avgdep1 = 0;
    for( int s = 0 ; s < 10000 ; s++ ){
        avgdep1 += t1.depth( s );
    } 
    avgdep1 = avgdep1/10000;

    // Test for finding time of single node in first tree 
    start = clock();
    t1.depth(9999);
    finish = clock();
    double single_time1 = elapsed_time(start, finish);




    // Test on overall time of second tree
    start = clock();
    for(int q = 0 ; q < 10000; q++ ){
        t2.depth( q );
    }      
    finish = clock();
    double overall_time2 = elapsed_time(start, finish); 

    double avgtime2 = 0;
    for( int k = 0 ; k < 10000 ; k++ ){
        start = clock();
        t2.depth( k );
        finish = clock();

        avgtime2 += elapsed_time(start, finish);
    } 
    avgtime2 = avgtime2/10000;

    // Finding average search depth for second tree
    int avgdep2 = 0;
    for( int p = 0 ; p < 10000 ; p++ ){
        avgdep2 += t2.depth( p );
    } 
    avgdep2 = avgdep2/10000;

    //Test for finding time of single node in second tree 
    start = clock();
    t2.depth(9999);
    finish = clock();
    double single_time2 = elapsed_time(start, finish);




    // Results 
    cout << endl;
    cout << "---------- Test Results ----------" << endl;
    cout << endl;
    
    cout << "Overall time taken for the membership tests of the first tree: " << endl;
    cout << overall_time1 << endl;
    cout << endl;

    cout << "Overall time taken for the membership tests of the second tree: " << endl;
    cout << overall_time2 << endl;
    cout << endl;

    cout << "Average time taken for the each membership test of the first tree: " << endl;
    cout << avgtime1 << endl;
    cout << endl;

    cout << "Average time taken for the each membership test of the second tree: " << endl;
    cout << avgtime2 << endl;
    cout << endl;

    cout << "Average search depth for the first tree: " << endl;
    cout << avgdep1 << endl;
    cout << endl;

    cout << "Average search depth for the second tree: " << endl;
    cout << avgdep2 << endl;
    cout << endl;

    cout << "Time taken for depth of last node in the first tree: " << endl;
    cout << single_time1 << endl;
    cout << endl;    

    cout << "Time taken for depth of last node in the second tree: " << endl;
    cout << single_time2 << endl;
}