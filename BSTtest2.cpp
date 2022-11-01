#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> t;
//    int NUMS = 400000;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key ;

    cout << "Start of BSTtest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ ){
        key = (key + GAP) % CAP ;
        t.insert( key );
    } 

    BinarySearchTree<int> t2;
    t2.insert(2); 
    //t2.insert(3); 
    //t2.insert(4); 
    //t2.height();
    t2.depth(3);
    //t2.displayLinks();

    /*
    if( NUMS < 40 ){
        cout << "Keys:" << endl ;
        t.printTree( );
        cout << "Tree:" << endl ;
        t.displayTree(); 
        cout << "Links:" << endl ;
        t.displayLinks(); 
        cout << "Height: " << endl;
        t.height();
        cout << "Depth of Node 8: " << endl;
        t.depth(8);
    }*/

/*
    for( i = 1; i < NUMS; i+= 2 )
        t.remove( i );

    if( NUMS < 40 ) t.printTree( );

    BinarySearchTree<int> t2;
    t2 = t;
*/
    cout << "End of BSTtest" << endl;

    return 0;
}
