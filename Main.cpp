#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "SplayTree.h"
#include <format>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

double elapsed_time(clock_t start,
                    clock_t finish) { // returns ellapsed time in milliseconds
  return (finish - start) / (double)(CLOCKS_PER_SEC / 1000);
}

template <typename Tree>
double timeInsertion(Tree &t, const std::vector<int> &arr) {
  clock_t start, finish;
  start = clock();
  // Stuff here is timed
  for (auto &i : arr) {
    t.insert(i);
  }

  // Code above this it timed
  finish = clock();
  return elapsed_time(start, finish);
}

template <typename Tree> double timeCountEven(Tree &t) {
  clock_t start, finish;
  start = clock();
  // Stuff below is timed
  t.countEven();
  // Stuff above is timed
  finish = clock();
  return elapsed_time(start, finish);
}

int main() {

  cout << "Smaller N1 and N2 size for demo tdisplay" << endl;
  cout << "N1: 10 items, N2: 20 items" << endl;
  const int N1Demo = 10;
  const int N2Demo = 20;
  vector<int> v1 = {5, 6, 1, 44, 512, 12, 41, 21, 7, 65};
  vector<int> v2 = {213, 312, 32, 12, 54, 53, 65, 52, 14, 78,
                    91,  43,  27, 89, 34, 67, 29, 73, 81, 99};

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
  cout << "size of n1 chosen is: " << N1 << ". Size of n2 chosen is: " << N2
       << "\n";

  vector<int> dataN1(N1);
  vector<int> dataN2(N2);
  for (int i = 0; i < N1; ++i) {
    dataN1[i] = rand() % N1;
  }
  for (int i = 0; i < N2; ++i) {
    dataN2[i] = rand() % N2;
  }

  BinarySearchTree<int> bstn1;
  BinarySearchTree<int> bstn2;
  RedBlackTree<int> rbtn1(-1);
  RedBlackTree<int> rbtn2(-1);
  SplayTree<int> sptn1;
  SplayTree<int> sptn2;
  double timeInsertionBSTn1 = timeInsertion(bstn1, dataN1);
  double timeInsertionBSTn2 = timeInsertion(bstn2, dataN2);
  double timeInsertionRBTn1 = timeInsertion(rbtn1, dataN1);
  double timeInsertionRBTn2 = timeInsertion(rbtn2, dataN2);
  double timeInsertionSPTn1 = timeInsertion(sptn1, dataN1);
  double timeInsertionSPTn2 = timeInsertion(sptn2, dataN2);
  double timeCountEvenBSTn1 = timeCountEven(bstn1);
  double timeCountEvenBSTn2 = timeCountEven(bstn2);
  double timeCountEvenRBTn1 = timeCountEven(rbtn1);
  double timeCountEvenRBTn2 = timeCountEven(rbtn2);
  double timeCountEvenSPTn1 = timeCountEven(sptn1);
  double timeCountEvenSPTn2 = timeCountEven(sptn2);

//   cout << "Time to insert set of size n1 into bst: " << timeInsertionBSTn1
//        << "\n";
//   cout << "Time to insert set of size n2 into bst: " << timeInsertionBSTn2
//        << "\n";
//   cout << "Time to insert set of size n1 into rbt: " << timeInsertionRBTn1
//        << "\n";
//   cout << "Time to insert set of size n2 into rbt: " << timeInsertionRBTn2
//        << "\n";
//   cout << "Time to insert set of size n1 into spt: " << timeInsertionSPTn1
//        << "\n";
//   cout << "Time to insert set of size n2 into spt: " << timeInsertionSPTn2
//        << "\n";

 //   cout << "Time to traverse bst containing n1 items with countEven: "
//        << timeCountEvenBSTn1 << "\n";
//   cout << "Time to traverse bst containing n2 items with countEven: "
//        << timeCountEvenBSTn2 << "\n";
//   cout << "Time to traverse rbt containing n1 items with countEven: "
//        << timeCountEvenRBTn1 << "\n";
//   cout << "Time to traverse rbt containing n2 items with countEven: "
//        << timeCountEvenRBTn2 << "\n";
//   cout << "Time to traverse spt containing n1 items with countEven: "
//        << timeCountEvenSPTn1 << "\n";
//   cout << "Time to traverse spt containing n2 items with countEven: "
//        << timeCountEvenSPTn2 << "\n";

  cout << "\n\n\n----------------------------\n";
  cout << "     Performance Report     \n";
  cout << "----------------------------\n";
  cout << "Name: Kale Moskowitz\n";
  cout << "Student Number: 301588993\n";
  cout << "Login ID: kom1@sfu.ca\n";
  cout << "Chosen Data Structures:\n";
  cout << "\tBinary Search Tree (BST)\n";
  cout << "\tRed Black Tree (RBT)\n";
  cout << "\tSplay Tree (SPT)\n";
  cout << "Set Sizes: n1 = " << N1 << ", n2 = " << N2 << "\n\n";

  cout << "Timing Measurements (ms):\n";
  cout << "----------------------------\n";
  cout << "Time to insert\n";
  cout << format("BST(n1): {}, BST(n2): {}\n"
                 "RBT(n1): {}, RBT(n2): {}\n"
                 "SPT(n1): {}, SPT(n2): {}\n\n",
                 timeInsertionBSTn1, timeInsertionBSTn2, timeInsertionRBTn1,
                 timeInsertionRBTn2, timeInsertionSPTn1, timeInsertionSPTn2);

    cout << "Time to traverse (countEven())\n";
    cout << format("BST(n1): {}, BST(n2): {}\n"
                 "RBT(n1): {}, RBT(n2): {}\n"
                 "SPT(n1): {}, SPT(n2): {}\n",
                 timeCountEvenBSTn1, timeCountEvenBSTn2, timeCountEvenRBTn1,
                 timeCountEvenRBTn2, timeCountEvenSPTn1, timeCountEvenSPTn2);
                 
  return 0;
}
