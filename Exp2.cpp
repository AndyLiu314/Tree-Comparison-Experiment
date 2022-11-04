#include <iostream>
#include <time.h>
#include "BinarySearchTree.h"
#include "AvlTree.h"
using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

int main( ) {
    cout << "Start of Exp2" << endl;
    clock_t start, finish;

    BinarySearchTree<int> t1; //Large BST
    int NUMS = 10000;
    const int GAP  = 3 ;
    const int CAP  = 10000;
    int i;
    int key ;

    //insertion time tests
    key = CAP/2;
    double avginsrt1 = 0;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        start = clock();
        t1.insert( key );
        finish = clock();

        avginsrt1 += elapsed_time(start,finish);  
    } 
    avginsrt1 = avginsrt1/10000; 

    //Finding Average key depth
    int avgdep1 = 0;
    for( int s = 0 ; s < 10000 ; s++ ){
        avgdep1 += t1.depth( s );
    } 
    avgdep1 = avgdep1/10000;

    // Membership tests for BST
    double avgtime1 = 0;
    double curtime1 = 0;
    long double mintime1 = 100000;
    int mindepth1 = 100000;
    long double maxtime1 = 0;
    int maxdepth1 = 0;
    for( int j = 0 ; j < 10000 ; j++ ){
        start = clock();
        t1.depth( j );
        finish = clock();

        int dep = t1.depth(j);

        if (dep > maxdepth1){
            maxdepth1 = dep;
        }

        if (dep < mindepth1){
            mindepth1 = dep;
        }

        curtime1 = elapsed_time(start, finish);
        if (curtime1 > maxtime1) {
            maxtime1 = curtime1;
        } 

        if (curtime1 < mintime1){
            mintime1 = curtime1;
        }

        avgtime1 += elapsed_time(start, finish);
    } 
    avgtime1 = avgtime1/10000;




    AvlTree<int> a1; // Large AVLtree
    double avginsrt2 = 0;
    for (int l = 0; l<10000; l++){
        start = clock(); 
        a1.insert(l); 
        finish = clock();

        avginsrt2 += elapsed_time(start, finish);
    }
    avginsrt2 = avginsrt2/10000;

    //finding avg key depth
    int avgdep2 = 0;
    for( int m = 0 ; m < 10000 ; m++ ){
        avgdep2 += a1.depth( m );
    } 
    avgdep2 = avgdep2/10000;

    // Membership tests for AVLtree
    double avgtime2 = 0;
    double curtime2 = 0;
    long double mintime2 = 100000;
    int mindepth2 = 100000;
    long double maxtime2 = 0;
    int maxdepth2 = 0;
    for( int k = 0 ; k < 10000 ; k++ ){
        start = clock();
        a1.depth( k );
        finish = clock();

        int dep = a1.depth(k);

        if (dep > maxdepth2){
            maxdepth2 = dep;
        }

        if (dep < mindepth2){
            mindepth2 = dep;
        }

        curtime2 = elapsed_time(start, finish);
        if (curtime2 > maxtime2) {
            maxtime2 = curtime2;
        } 

        if (curtime2 < mintime2){
            mintime2 = curtime2;
        }

        avgtime2 += elapsed_time(start, finish);
    } 
    avgtime2 = avgtime2/10000;

    //Results
    cout << endl;
    cout << "---------- Test Results ----------" << endl;
    cout << endl;

    cout << "Average time taken for insertions in the BST: " << endl;
    cout << avginsrt1 << endl;
    cout << endl;

    cout << "Average time taken for insertions in the AVLtree: " << endl;
    cout << avginsrt2 << endl;
    cout << endl;

    cout << "Height of the BST: " << endl;
    t1.height();
    cout << endl;

    cout << "Height of the AVLtree: " << endl;
    a1.height();
    cout << endl;

    cout << "Average key depth for the BST: " << endl;
    cout << avgdep1 << endl;
    cout << endl;

    cout << "Average key depth for the AVLtree: " << endl;
    cout << avgdep2 << endl;
    cout << endl;

    cout << "Membership tests for BST: " << endl;
    cout << "Minimum time: " << mintime1 << endl;
    cout << "Minimum depth: " << mindepth1 << endl;
    cout << "Maximum time: " << maxtime1 << endl;
    cout << "Maximum depth: " << maxdepth1 << endl;
    cout << "Average time: " << avgtime1 << endl;
    cout << "Average depths were found in previous tests" << endl;
    cout << endl;

    cout << "Membership tests for AVLtree: " << endl;
    cout << "Minimum time: " << mintime2 << endl;
    cout << "Minimum depth: " << mindepth2 << endl;
    cout << "Maximum time: " << maxtime2 << endl;
    cout << "Maximum depth: " << maxdepth2 << endl;
    cout << "Average time: " << avgtime2 << endl;
    cout << "Average depths were found in previous tests" << endl;
    cout << endl;

    cout << endl;
    cout << "---------- Tests Finished ----------" << endl;
    cout << endl;
}