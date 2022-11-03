#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main( ) {
    BinarySearchTree<int> t;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of DLtest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    } 

    cout << "Test Tree 1 Links:" << endl ;
    cout << "Check if the addresses of the left and right child nodes match with their actual respective addresses" << endl ;
    cout << "Parent nodes with no children should have L:0 and R:0" << endl;
    t.displayLinks();
    cout << "If they all match then the test has passed" << endl;
    cout << endl;

    BinarySearchTree<int> t1; // Tree with one node
    t1.insert(2);
    cout << "Test Tree 2 Links:" << endl ;
    t1.displayLinks();
    cout << "If the addresses of the child nodes are L:0 and R:0, then the test has passed" << endl;
    cout << endl;

    BinarySearchTree<int> t2; // Empty tree
    cout << "Test Tree 3 Links:" << endl ;
    cout << "Expected Outcome: " << endl;
    cout << "Empty tree" << endl;
    cout << "Actual Outcome: " << endl;
    t2.displayLinks();
}