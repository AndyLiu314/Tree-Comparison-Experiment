#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main( ) {
    BinarySearchTree<int> t;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 23;
    int i;
    int key ;

    cout << "Start of Htest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    } 

    if( NUMS < 40 ){
        cout << "Test Tree 1:" << endl; //Test for a filled tree
        t.displayTree(); 
        cout << "Expected Height Output: " << endl;
        cout << "5" << endl;
        cout << "Actual Height Output: " << endl;
        t.height();
        cout << endl;
    }

    BinarySearchTree<int> t1; //Test for a tree with only one node
    t1.insert(2); 

    cout << "Test Tree 2:" << endl;
    t1.displayTree();
    cout << "Expected Height Output: " << endl;
    cout << "0" << endl;
    cout << "Actual Height Output: " << endl;
    t1.height();
    cout << endl;

    BinarySearchTree<int> t2; //Test for an empty tree

    cout << "Test Tree 3:" << endl;
    t2.displayTree();
    cout << "Expected Height Output: " << endl;
    cout << "0" << endl;
    cout << "Actual Height Output: " << endl;
    t1.height();
}