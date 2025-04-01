#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "SplayTree.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "Smaller N1 and N2 size for demo tdisplay" << endl;
    cout << "N1: 10 items, N2: 20 items" << endl;
    const int N1Demo = 10;
    const int N2Demo = 20;
    vector<int> v1 = { 5, 6, 1,44, 512, 12, 41, 21, 7, 65};
    vector<int> v2 = {213, 312, 32, 12, 54, 53, 65, 52, 14, 78, 
        91, 43, 27, 89, 34, 67, 29, 73, 81, 99};

    

    BinarySearchTree<int> bst1;
    BinarySearchTree<int> bst2;
    RedBlackTree<int> rbt1(-1);
    RedBlackTree<int> rbt2(-1);
    SplayTree<int> spt1;
    SplayTree<int> spt2;

    cout << "Binary Search Tree 1" << endl;
    for (int i = 0; i < N1Demo; ++i) {
        bst1.insert(v1[i]);
    }
    bst1.tdisplay();
    cout << "Binary Search Tree 2" << endl;
    for (int i = 0; i < N2Demo; ++i) {
        bst2.insert(v2[i]);
    }
    bst2.tdisplay();
    cout << "Red Black Tree 1" << endl;
    for (int i = 0; i < N1Demo; ++i) {
        rbt1.insert(v1[i]);
    }
    rbt1.tdisplay();
    cout << "Red Black Tree 2" << endl;
    for (int i = 0; i < N2Demo; ++i) {
        rbt2.insert(v2[i]);
    }
    rbt2.tdisplay();
    cout << "Splay Tree 1" << endl;
    for (int i = 0; i < N1Demo; ++i) {
        spt1.insert(v1[i]);
    }
    spt1.tdisplay();
    cout << "Splay Tree 2" << endl;
    for (int i = 0; i < N2Demo; ++i) {
        spt2.insert(v2[i]);
    }
    spt2.tdisplay();

    
    cout << "Larger N1 and N2 size for timing report" << endl;
    const int N1 = 1000000;
    const int N2 = 10000000;

    vector<int> v3(N1);
    vector<int> v4(N2);
    for (int i = 0; i < N1; ++i) {
        v3[i] = rand() % 1000000;
    }
    for (int i = 0; i < N2; ++i) {
        v4[i] = rand() % 10000000;
    }

    


    return 0;
}