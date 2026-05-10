#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Book structure containing ID, title, and author
struct Book {
    int id;
    string title;
    string author;
};

// AVL Tree node
struct AVLNode {
    Book data;          // Book information
    AVLNode* left;      // Pointer to left child
    AVLNode* right;     // Pointer to right child
    int height;         // Height of the node (for balancing)

    // Constructor
    AVLNode(Book b) : data(b), left(nullptr), right(nullptr), height(1) {}
};

class AVL {
private:
    AVLNode* root;      // Root of the AVL tree

    // Utility functions
    int getHeight(AVLNode* node);            // Returns height of a node
    int getBalance(AVLNode* node);           // Returns balance factor (left - right)
    void updateHeight(AVLNode* node);        // Updates height based on children

    // Rotation functions (core AVL balancing)
    AVLNode* rightRotate(AVLNode* y);        // Right rotation (LL case)
    AVLNode* leftRotate(AVLNode* x);         // Left rotation (RR case)
    AVLNode* leftRightRotate(AVLNode* node); // Left-Right rotation (LR case)
    AVLNode* rightLeftRotate(AVLNode* node); // Right-Left rotation (RL case)
    AVLNode* balanceNode(AVLNode* node);     // Check balance and perform rotations

    // Core operations
    AVLNode* insert(AVLNode* node, Book book);   // Recursive insert
    AVLNode* deleteNode(AVLNode* node, int id);  // Recursive delete
    AVLNode* findMin(AVLNode* node);             // Find node with minimum ID

    // Search with step counter
    AVLNode* search(AVLNode* node, int id, int& steps);

    // Traversal
    void inorder(AVLNode* node);                 // In-order traversal

    // Additional features
    void rangeSearch(AVLNode* node, int minID, int maxID); // Print books in range
    void closestID(AVLNode* node, int target, int& closest); // Find closest ID

public:
    AVL();                                 // Constructor

    // Public interface
    void insert(Book book);                // Insert a book
    void deleteBook(int id);               // Delete a book by ID
    void searchBook(int id);               // Search and display book + steps
    void displayBooks();                   // Display all books sorted by ID
    int getHeight();                       // Return tree height
    void findBooksInRange(int minID, int maxID);   // Range query
    void findClosestBook(int target);      // Find closest book ID
};

#endif