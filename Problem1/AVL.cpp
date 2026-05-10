#include "AVL.h"

// Constructor
AVL::AVL() : root(nullptr) {}

// ========== Utility Functions ==========

// Returns the height of a node (0 if null)
int AVL::getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// Returns balance factor (height(left) - height(right))
int AVL::getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Updates a node's height based on its children
void AVL::updateHeight(AVLNode* node) {
    if (node)
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// ========== Rotation Implementations ==========

// Right rotation (used for LL case)
AVLNode* AVL::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root of this subtree
}

// Left rotation (used for RR case)
AVLNode* AVL::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y; // new root
}

// Left-Right rotation (LR case)
AVLNode* AVL::leftRightRotate(AVLNode* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

// Right-Left rotation (RL case)
AVLNode* AVL::rightLeftRotate(AVLNode* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

// Balances a node if needed using rotations
AVLNode* AVL::balanceNode(AVLNode* node) {
    if (!node) return nullptr;

    updateHeight(node);
    int balance = getBalance(node);

    // Left heavy
    if (balance > 1) {
        // Left-Left case
        if (getBalance(node->left) >= 0)
            return rightRotate(node);
        // Left-Right case
        else
            return leftRightRotate(node);
    }
    // Right heavy
    if (balance < -1) {
        // Right-Right case
        if (getBalance(node->right) <= 0)
            return leftRotate(node);
        // Right-Left case
        else
            return rightLeftRotate(node);
    }
    return node; // already balanced
}

// ========== Insertion ==========

// Recursive insertion with automatic balancing
AVLNode* AVL::insert(AVLNode* node, Book book) {
    if (!node)
        return new AVLNode(book);

    if (book.id < node->data.id)
        node->left = insert(node->left, book);
    else if (book.id > node->data.id)
        node->right = insert(node->right, book);
    else
        return node; // duplicate ID not allowed

    return balanceNode(node);
}

// Public insert wrapper
void AVL::insert(Book book) {
    root = insert(root, book);
}

// ========== Deletion ==========

// Finds the node with minimum ID in a subtree
AVLNode* AVL::findMin(AVLNode* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Recursive deletion with balancing
AVLNode* AVL::deleteNode(AVLNode* node, int id) {
    if (!node) return nullptr;

    if (id < node->data.id)
        node->left = deleteNode(node->left, id);
    else if (id > node->data.id)
        node->right = deleteNode(node->right, id);
    else {
        // Node to delete found
        if (!node->left || !node->right) {
            // 0 or 1 child
            AVLNode* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            // 2 children: get inorder successor
            AVLNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data.id);
        }
    }
    return balanceNode(node);
}

void AVL::deleteBook(int id) {
    root = deleteNode(root, id);
}

// ========== Search with Step Counting ==========

// Recursive search that increments steps counter
AVLNode* AVL::search(AVLNode* node, int id, int& steps) {
    if (!node) return nullptr;
    steps++;
    if (id == node->data.id)
        return node;
    if (id < node->data.id)
        return search(node->left, id, steps);
    else
        return search(node->right, id, steps);
}

void AVL::searchBook(int id) {
    int steps = 0;
    AVLNode* result = search(root, id, steps);
    if (result) {
        cout << "\nBook Found:\n";
        cout << "ID: " << result->data.id << "\nTitle: " << result->data.title
             << "\nAuthor: " << result->data.author << endl;
    } else {
        cout << "\nBook with ID " << id << " not found.\n";
    }
    cout << "Search steps: " << steps << endl;
}

// ========== In-order Traversal ==========

// Prints books in sorted order (by ID)
void AVL::inorder(AVLNode* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data.id << " - " << node->data.title << " - " << node->data.author << endl;
    inorder(node->right);
}

void AVL::displayBooks() {
    inorder(root);
}

int AVL::getHeight() {
    return getHeight(root);
}

// ========== Range Search (Feature 1) ==========

// Prints all books with ID between minID and maxID (inclusive)
void AVL::rangeSearch(AVLNode* node, int minID, int maxID) {
    if (!node) return;
    if (node->data.id > minID)
        rangeSearch(node->left, minID, maxID);
    if (node->data.id >= minID && node->data.id <= maxID) {
        cout << node->data.id << " - " << node->data.title << " - " << node->data.author << endl;
    }
    if (node->data.id < maxID)
        rangeSearch(node->right, minID, maxID);
}

void AVL::findBooksInRange(int minID, int maxID) {
    cout << "\nBooks between " << minID << " and " << maxID << ":\n";
    rangeSearch(root, minID, maxID);
}

// ========== Closest ID (Feature 2) ==========

// Recursively finds the ID closest to target
void AVL::closestID(AVLNode* node, int target, int& closest) {
    if (!node) return;
    if (abs(node->data.id - target) < abs(closest - target))
        closest = node->data.id;
    if (target < node->data.id)
        closestID(node->left, target, closest);
    else if (target > node->data.id)
        closestID(node->right, target, closest);
}

void AVL::findClosestBook(int target) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    int closest = root->data.id;
    closestID(root, target, closest);
    cout << "\nClosest book ID to " << target << " is: " << closest << endl;
}