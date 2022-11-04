#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
using namespace std;

int main( ) {
    BinarySearchTree<int> t;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of Dtest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    } 

    if( NUMS < 40 ){
        cout << "Test Tree 1:" << endl; //Test for a filled tree
        t.displayTree(); 
        cout << endl;

        cout << "Test Case: Root Node " << endl;
        cout << "Expected Depth Output: " << endl;
        cout << "0" << endl;
        cout << "Actual Depth Output: " << endl;
        t.depth(12);
        cout << endl;

        cout << "Test Case: Non-root Node " << endl;
        cout << "Expected Depth Output: " << endl;
        cout << "3" << endl;
        cout << "Actual Depth Output: " << endl;
        t.depth(8);
        cout << endl;

        cout << "Test Case: Node Not Found" << endl;
        cout << "Expected Depth Output: " << endl;
        cout << "BST does not contain: 7" << endl;
        cout << "Depth of Search: 3" << endl;
        cout << endl;
        cout << "Actual Depth Output: " << endl;
        t.depth(7);
        cout << endl;
    }

    BinarySearchTree<int> t1; // Test for a single node tree
    t1.insert(2);

    cout << "Test Tree 2:" << endl;
    t1.displayTree(); 
    cout << endl;

    cout << "Test Case: Node Not Found" << endl;
    cout << "Expected Depth Output: " << endl;
    cout << "BST does not contain: 3" << endl;
    cout << "Depth of Search: 1" << endl;
    cout << endl;
    cout << "Actual Depth Output: " << endl;
    t1.depth(3);
    cout << endl;    

    BinarySearchTree<int> t2; // Test for an empty tree
    cout << "Test Tree 3:" << endl;
    cout << endl;

    cout << "Test Case: Empty Tree" << endl;
    cout << "Expected Depth Output: " << endl;
    cout << "Empty tree" << endl;
    cout << endl;
    cout << "Actual Depth Output: " << endl;
    t2.depth(3);
}