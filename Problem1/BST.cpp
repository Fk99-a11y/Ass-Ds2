#include "BST.h"
#include <cmath>

// Constructor
BST::BST() {
    root = nullptr;
}

// ================= INSERT =================

// Insert node recursively
Node* BST::insert(Node* node, Book book) {

    // Create new node if place is empty
    if (node == nullptr)
        return new Node(book);

    // Insert in left subtree
    if (book.id < node->data.id)
        node->left = insert(node->left, book);

    // Insert in right subtree
    else if (book.id > node->data.id)
        node->right = insert(node->right, book);

    return node;
}

// Public insert function
void BST::insert(Book book) {
    root = insert(root, book);
}

// ================= DELETE =================

// Find minimum node in subtree
Node* BST::findMin(Node* node) {

    while (node && node->left != nullptr)
        node = node->left;

    return node;
}

// Delete node recursively
Node* BST::deleteNode(Node* node, int id) {

    if (node == nullptr)
        return node;

    // Search in left subtree
    if (id < node->data.id)
        node->left = deleteNode(node->left, id);

    // Search in right subtree
    else if (id > node->data.id)
        node->right = deleteNode(node->right, id);

    else {

        // Case 1: No left child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // Case 2: No right child
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(node->right);

        node->data = temp->data;

        node->right = deleteNode(node->right, temp->data.id);
    }

    return node;
}

// Public delete function
void BST::deleteBook(int id) {
    root = deleteNode(root, id);
}

// ================= SEARCH =================

// Search for a book and count steps
Node* BST::search(Node* node, int id, int& steps) {

    if (node == nullptr)
        return nullptr;

    steps++;

    // Book found
    if (id == node->data.id)
        return node;

    // Search left
    if (id < node->data.id)
        return search(node->left, id, steps);

    // Search right
    return search(node->right, id, steps);
}

// Public search function
void BST::searchBook(int id) {

    int steps = 0;

    Node* result = search(root, id, steps);

    if (result) {
        cout << "\nBook Found:\n";
        cout << "ID: " << result->data.id << endl;
        cout << "Title: " << result->data.title << endl;
        cout << "Author: " << result->data.author << endl;
    }

    else {
        cout << "\nBook not found.\n";
    }

    cout << "Search Steps: " << steps << endl;
}

// ================= TRAVERSAL =================

// In-order traversal
void BST::inorder(Node* node) {

    if (node == nullptr)
        return;

    inorder(node->left);

    cout << node->data.id << " - "
        << node->data.title << " - "
        << node->data.author << endl;

    inorder(node->right);
}

// Display all books sorted by ID
void BST::displayBooks() {
    inorder(root);
}

// ================= TREE HEIGHT =================

// Calculate tree height
int BST::height(Node* node) {

    if (node == nullptr)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return max(leftHeight, rightHeight) + 1;
}

// Public height function
int BST::getHeight() {
    return height(root);
}

// ================= RANGE SEARCH =================

// Print books within range
void BST::rangeSearch(Node* node, int min, int max) {

    if (node == nullptr)
        return;

    // Visit left subtree
    if (node->data.id > min)
        rangeSearch(node->left, min, max);

    // Print current node if inside range
    if (node->data.id >= min && node->data.id <= max) {

        cout << node->data.id << " - "
            << node->data.title << " - "
            << node->data.author << endl;
    }

    // Visit right subtree
    if (node->data.id < max)
        rangeSearch(node->right, min, max);
}

// Public range search
void BST::findBooksInRange(int min, int max) {

    cout << "\nBooks between "
        << min << " and "
        << max << ":\n";

    rangeSearch(root, min, max);
}

// ================= CLOSEST BOOK =================

// Find closest ID recursively
void BST::closestID(Node* node, int target, int& closest) {

    if (node == nullptr)
        return;

    // Update closest value
    if (abs(node->data.id - target) < abs(closest - target))
        closest = node->data.id;

    // Continue search
    if (target < node->data.id)
        closestID(node->left, target, closest);

    else if (target > node->data.id)
        closestID(node->right, target, closest);
}

// Public closest book function
void BST::findClosestBook(int target) {

    int closest = root->data.id;

    closestID(root, target, closest);

    cout << "\nClosest Book ID to "
        << target
        << " is: "
        << closest << endl;
}
