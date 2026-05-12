#ifndef BST_H
#define BST_H
#include "Book.h"
#include <iostream>
#include <climits>

using namespace std;
// ================= NODE STRUCT =================

// Tree node
struct Node {

    Book data;

    Node* left;
    Node* right;

    // Constructor
    Node(Book b) {
        data = b;
        left = right = nullptr;
    }
};

// ================= BST CLASS =================

class BST {

private:

    Node* root;

    // Core BST operations
    Node* insert(Node* node, Book book);

    Node* deleteNode(Node* node, int id);

    Node* findMin(Node* node);

    Node* search(Node* node, int id, int& steps);

    // Traversal
    void inorder(Node* node);

    // Tree height
    int height(Node* node);

    // Additional features
    void rangeSearch(Node* node, int min, int max);

    void closestID(Node* node, int target, int& closest);

public:

    // Constructor
    BST();

    // Insert new book
    void insert(Book book);

    // Delete book by ID
    void deleteBook(int id);

    // Search for book by ID
    void searchBook(int id);

    // Display books in sorted order
    void displayBooks();

    // Return tree height
    int getHeight();

    // Display books within range
    void findBooksInRange(int min, int max);

    // Find closest book ID
    void findClosestBook(int target);
};

#endif
