#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "RedBlackTree.h"
#include <iostream>
#include <random>
#include <vector>


int randInt(int low, int hi)
{
  int n = hi - low + 1;
  int i = rand() % n;
  if (i < 0)
  {
    i = -i;
  }
  return low + i;
}



int main(){

    const int n1Size = 1000000;
    const int n1SizeDemo = 10;
    const int n2Size = 10000000;
    const int n2SizeDemo = 25;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distn1(1, n1Size);
    std::uniform_int_distribution<int> distn1demo(1, n1SizeDemo);
    std::uniform_int_distribution<int> distn2(1,n2Size);
    std::uniform_int_distribution<int> distn2demo(1, n2SizeDemo);
    
    std::vector<int> n1;
    n1.reserve(n1Size);
    std::vector<int> n2;
    n2.reserve(n2Size);

    std::vector<int> n1Demo;
    n1Demo.reserve(n1SizeDemo);
    std::vector<int> n2Demo;
    n2Demo.resize(n2SizeDemo);


    for (size_t i{0}; i < n1SizeDemo; i++)
    {
      n1Demo.push_back(distn1demo(gen));
    }
    for (size_t i{0}; i < n2SizeDemo; i++)
    {
      n2Demo.push_back(distn2demo(gen));
    }


    // for (size_t i{0}; i < n1Size; i++)
    // {
    //   n1.push_back(distn1(gen));
    // }
    // for (size_t i{0}; i < n2Size; i++)
    // {
    //   n2.push_back(distn2(gen));
    // }
    BinarySearchTree<int> bst1demo;
    BinarySearchTree<int> bst2demo;

    SplayTree<int> st1demo;
    SplayTree<int> st2demo;

    RedBlackTree<int> rbt1demo(-1);
    RedBlackTree<int> rbt2demo(-1);
 
    // BinarySearchTree<int> bst1;
    // BinarySearchTree<int> bst2;

    // SplayTree<int> st1;
    // SplayTree<int> st2;

    // RedBlackTree<int> rbt1(-1);
    // RedBlackTree<int> rbt2(-1);
 
    for (auto &i  : n1Demo) {
        bst1demo.insert(i);
    }
    for (auto &i  : n2Demo) {
        bst2demo.insert(i);
    }
    for (auto &i  : n1Demo) {
        st1demo.insert(i);
    }
    for (auto &i  : n2Demo) {
        st2demo.insert(i);
    }
    for (auto &i  : n1Demo) {
        rbt1demo.insert(i);
    }
    for (auto &i  : n2Demo) {
        rbt2demo.insert(i);
    }




    // for (auto &i  : n1) {
    //     bst1.insert(i);
    // }
    // for (auto &i  : n2) {
    //     bst2.insert(i);
    // }
    // for (auto &i  : n1) {
    //     st1.insert(i);
    // }
    // for (auto &i  : n2) {
    //     st2.insert(i);
    // }
    // for (auto &i  : n1) {
    //     rbt1.insert(i);
    // }
    // for (auto &i  : n2) {
    //     rbt2.insert(i);
    // }

    // cout << "Number of Even values in bst1 is: " << bst1.countEven() << endl;

    // cout << "Number of Even values in bst2 is: " << bst2.countEven() << endl;

    // cout << "Number of Even values in st1 is: " << st1.countEven() << endl;

    // cout << "Number of Even values in st2 is: " << st2.countEven() << endl;

    // cout << "Number of Even values in rbt1 is: " << rbt1.countEven() << endl;

    // cout << "Number of Even values in rbt2 is: " << rbt2.countEven() << endl;

    cout << "Demo to show t-display working on smaller Data structures!!\n\n";

    bst1demo.tdisplay();
    bst2demo.tdisplay();
    st1demo.tdisplay();
    st2demo.tdisplay(); 
    rbt1demo.tdisplay();
    rbt2demo.tdisplay();
    


    


    return 0;
}
