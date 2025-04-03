#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include "SplayTree.h"
#include <algorithm>
#include <ctime>
#include <format>
#include <iostream>
#include <iterator>
#include <random>
#include <set>
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

template <typename Tree> double timeTDisplay(Tree &t) {
  clock_t start, finish;
  start = clock();
  // Stuff below is timed
  t.tdisplay();
  // Stuff above is timed
  finish = clock();
  return elapsed_time(start, finish);
}

int main() {

  const int N1 = 1000000;
  const int N2 = 10000000;

  cout << "size of n1 chosen is: " << N1 << ". Size of n2 chosen is: " << N2
       << "\n";

  vector<int> dataN1(N1);
  vector<int> dataN2(N2);
  for (int i = 0; i < N1; ++i) {
    dataN1[i] = i + 1;
  }

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(dataN1), std::end(dataN1), rng);

  for (int i = 0; i < N2; ++i) {
    dataN2[i] = i + 1;
  }
  std::shuffle(std::begin(dataN2), std::end(dataN2), rng);

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
  cout << "\nBST N1 Tdisplay\n\n";
  double timeTdisplayBSTn1 = timeTDisplay(bstn1);
  cout << "\nBST N2 Tdisplay\n\n";
  double timeTdisplayBSTn2 = timeTDisplay(bstn2);
  cout << "\nRBT N1 Tdisplay\n\n";
  double timeTdisplayRBTn1 = timeTDisplay(rbtn1);
  cout << "\nRBT N2 Tdisplay\n\n";
  double timeTdisplayRBTn2 = timeTDisplay(rbtn2);
  cout << "\nSPT N1 Tdisplay\n\n";
  double timeTdisplaySPTn1 = timeTDisplay(sptn1);
  cout << "\nSPT N2 Tdisplay\n\n";
  double timeTdisplaySPTn2 = timeTDisplay(sptn2);

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
  cout << "Time to traverse (tdisplay())\n";
  cout << format("BST(n1): {}, BST(n2): {}\n"
                 "RBT(n1): {}, RBT(n2): {}\n"
                 "SPT(n1): {}, SPT(n2): {}\n",
                 timeTdisplayBSTn1, timeTdisplayBSTn2, timeTdisplayRBTn1,
                 timeTdisplayRBTn2, timeTdisplaySPTn1, timeTdisplaySPTn2);

  return 0;
}
