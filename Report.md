# 1 
Kale Moskowitz
301588993
kom1@sfu.ca
CMPT225 Assignment 4

# 2 Tree Types
- Binary Search Tree
- RedBlack Tree
- Splay Tree

# 3 Keys Beinginserted
n1 is of size One Million
n2 is of size Ten Million

Each set of data was creating by generating a vector of integers 1 to n1 or n2 respectively. The vector was then suffled to ensure a random insertion order. 

I decided on this to simulate average case performance of the data structures.

# 4 Question being asked
The goal of the experiment was to compare performance of different search trees under larger scale sets. Specifically how well do BSTs, RBTs, and SPTs perform in terms of 
- Insertion Time
- Traversal time for countEven()
- Traversal time to print a visual representation of the tree.

# 5 Table of times obtained by program

# 6 Short Statement of observqations

# 7 Short statement of any inferences from data

# 8 Anything Else from 



----------------------------
     Performance Report     
----------------------------
Name: Kale Moskowitz
Student Number: 301588993
Login ID: kom1@sfu.ca
Chosen Data Structures:
        Binary Search Tree (BST)
        Red Black Tree (RBT)
        Splay Tree (SPT)
Set Sizes: n1 = 1000000, n2 = 10000000

=== Insertion Times (ms) ===
  BST(n1): 480.561   |  BST(n2): 10747.1
  RBT(n1): 482.997   |  RBT(n2): 10251.4
  SPT(n1): 687.542   |  SPT(n2): 16652.2

=== Time to Traverse (countEven()) ===
  BST(n1): 42.721   |  BST(n2): 503.558
  RBT(n1): 33.425   |  RBT(n2): 367.845
  SPT(n1): 38.679   |  SPT(n2): 477.514

=== Time to Traverse (tdisplay()) ===
  BST(n1): 2291.81   |  BST(n2): 24733.5
  RBT(n1): 2125.52   |  RBT(n2): 24216.3
  SPT(n1): 2980.97   |  SPT(n2): 30989.5

