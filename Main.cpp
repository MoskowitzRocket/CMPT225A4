#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include <cstdlib>
#include <ctime>

// Assuming these class declarations are in separate header files
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "RedBlackTree.h"

// Constants for tree sizes
#define REPORT_SIZE_N1 1000000   // Large size for timing reports
#define REPORT_SIZE_N2 10000000   // Larger size for timing reports
#define DISPLAY_SIZE_N1 10     // Small size for readable tree display
#define DISPLAY_SIZE_N2 20     // Slightly larger size for tree display

// Template function to populate a tree with random values
template <typename Tree>
void populateTree(Tree& tree, int size) {
    for (int i = 0; i < size; i++) {
        tree.insert(rand() % (size * 10)); // Random values between 0 and size*10-1
    }
}

// Template function to time the counteven operation
template <typename Tree>
double timeCountEven(Tree& tree) {
    auto start = std::chrono::high_resolution_clock::now();
    int count = tree.countEven();
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

int main(int argc, char* argv[]) {


    // Set random seed
    std::srand(std::time(nullptr));
    
    // Determine if we're in report mode (timing measurements) or display mode
    bool report_mode = true;  // Default to report mode with larger trees
    
    // If command line argument "display" is provided, switch to display mode
    if (argc > 1 && std::string(argv[1]) == "display") {
        report_mode = false;
    }
    
    int n1 = report_mode ? REPORT_SIZE_N1 : DISPLAY_SIZE_N1;
    int n2 = report_mode ? REPORT_SIZE_N2 : DISPLAY_SIZE_N2;
    
    std::cout << "**Report: Tree Data Structure Performance Analysis**\n\n";
    std::cout << "Data Structures: Binary Search Tree, Splay Tree, and Red-Black Tree\n";
    std::cout << "Set sizes: n1 = " << n1 << " and n2 = " << n2 << "\n\n";
    
    // Table header for timing results
    std::cout << std::left
              << std::setw(20) << "Tree Type"
              << std::setw(10) << "Size"
              << std::setw(20) << "CountEven Time (ms)"
              << "\n";
    std::cout << std::setw(20) << "--------------------"
              << std::setw(10) << "----------"
              << std::setw(20) << "--------------------"
              << "\n";
    
    // Create and test BinarySearchTree with n1 elements
    BinarySearchTree<int> bst1;
    populateTree(bst1, n1);
    if (!report_mode) {
        std::cout << "\nBinary Search Tree of size " << n1 << ":\n";
        bst1.tdisplay();
    }
    double bst1_time = timeCountEven(bst1);
    
    std::cout << std::left
              << std::setw(20) << "Binary Search Tree"
              << std::setw(10) << n1
              << std::setw(20) << std::fixed << std::setprecision(2) << bst1_time
              << "\n";
    
    // Create and test BinarySearchTree with n2 elements
    BinarySearchTree<int> bst2;
    populateTree(bst2, n2);
    if (!report_mode) {
        std::cout << "\nBinary Search Tree of size " << n2 << ":\n";
        bst2.tdisplay();
    }
    double bst2_time = timeCountEven(bst2);
    
    std::cout << std::left
              << std::setw(20) << "Binary Search Tree"
              << std::setw(10) << n2
              << std::setw(20) << std::fixed << std::setprecision(2) << bst2_time
              << "\n";
    
    // Create and test SplayTree with n1 elements
    SplayTree<int> splay1;
    populateTree(splay1, n1);
    if (!report_mode) {
        std::cout << "\nSplay Tree of size " << n1 << ":\n";
        splay1.tdisplay();
    }
    double splay1_time = timeCountEven(splay1);
    
    std::cout << std::left
              << std::setw(20) << "Splay Tree"
              << std::setw(10) << n1
              << std::setw(20) << std::fixed << std::setprecision(2) << splay1_time
              << "\n";
    
    // Create and test SplayTree with n2 elements
    SplayTree<int> splay2;
    populateTree(splay2, n2);
    if (!report_mode) {
        std::cout << "\nSplay Tree of size " << n2 << ":\n";
        splay2.tdisplay();
    }
    double splay2_time = timeCountEven(splay2);
    
    std::cout << std::left
              << std::setw(20) << "Splay Tree"
              << std::setw(10) << n2
              << std::setw(20) << std::fixed << std::setprecision(2) << splay2_time
              << "\n";
    
    // Create and test RedBlackTree with n1 elements
    RedBlackTree<int> rb1(-1);
    populateTree(rb1, n1);
    if (!report_mode) {
        std::cout << "\nRed-Black Tree of size " << n1 << ":\n";
        rb1.tdisplay();
    }
    double rb1_time = timeCountEven(rb1);
    
    std::cout << std::left
              << std::setw(20) << "Red-Black Tree"
              << std::setw(10) << n1
              << std::setw(20) << std::fixed << std::setprecision(2) << rb1_time
              << "\n";
    
    // Create and test RedBlackTree with n2 elements
    RedBlackTree<int> rb2(-1);
    populateTree(rb2, n2);
    if (!report_mode) {
        std::cout << "\nRed-Black Tree of size " << n2 << ":\n";
        rb2.tdisplay();
    }
    double rb2_time = timeCountEven(rb2);
    
    std::cout << std::left
              << std::setw(20) << "Red-Black Tree"
              << std::setw(10) << n2
              << std::setw(20) << std::fixed << std::setprecision(2) << rb2_time
              << "\n";
    
    // Analysis summary
    std::cout << "\nAnalysis Summary:\n";
    
    // Compare performance at size n1
    std::cout << "1. Performance Comparison at size n1 = " << n1 << ":\n";
    double fastest_n1 = std::min({bst1_time, splay1_time, rb1_time});
    std::cout << "   - Binary Search Tree: " << std::fixed << std::setprecision(2) << bst1_time << " ms ("
              << std::fixed << std::setprecision(2) << (bst1_time / fastest_n1) << "x relative to fastest)\n";
    std::cout << "   - Splay Tree: " << std::fixed << std::setprecision(2) << splay1_time << " ms ("
              << std::fixed << std::setprecision(2) << (splay1_time / fastest_n1) << "x relative to fastest)\n";
    std::cout << "   - Red-Black Tree: " << std::fixed << std::setprecision(2) << rb1_time << " ms ("
              << std::fixed << std::setprecision(2) << (rb1_time / fastest_n1) << "x relative to fastest)\n";
    
    // Compare performance at size n2
    std::cout << "2. Performance Comparison at size n2 = " << n2 << ":\n";
    double fastest_n2 = std::min({bst2_time, splay2_time, rb2_time});
    std::cout << "   - Binary Search Tree: " << std::fixed << std::setprecision(2) << bst2_time << " ms ("
              << std::fixed << std::setprecision(2) << (bst2_time / fastest_n2) << "x relative to fastest)\n";
    std::cout << "   - Splay Tree: " << std::fixed << std::setprecision(2) << splay2_time << " ms ("
              << std::fixed << std::setprecision(2) << (splay2_time / fastest_n2) << "x relative to fastest)\n";
    std::cout << "   - Red-Black Tree: " << std::fixed << std::setprecision(2) << rb2_time << " ms ("
              << std::fixed << std::setprecision(2) << (rb2_time / fastest_n2) << "x relative to fastest)\n";
    
    // Scalability analysis
    std::cout << "3. Scalability (n2/n1 = " << (n2 / n1) << "):\n";
    std::cout << "   - Binary Search Tree: " << std::fixed << std::setprecision(2) << (bst2_time / bst1_time) << "x slower\n";
    std::cout << "   - Splay Tree: " << std::fixed << std::setprecision(2) << (splay2_time / splay1_time) << "x slower\n";
    std::cout << "   - Red-Black Tree: " << std::fixed << std::setprecision(2) << (rb2_time / rb1_time) << "x slower\n";
    
    return 0;
}