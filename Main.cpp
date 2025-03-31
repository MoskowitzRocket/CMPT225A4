#include "BinarySearchTree.h"
#include <iostream>
//#include <random>


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

    BinarySearchTree<int> BST;
  
    for (size_t i{0}; i < 1000000;i++)
    {
      BST.insert(randInt(1, 1000000));
    }

    BST.tdisplay();
    std::cout << "Number of Even Values in BST: " << BST.countEven() << std::endl;
    return 0;
}
