#include "BST.h"

// =====================================
// CS214 - Assignment 2
// Problem 1: BST Implementation
// Member 1 Responsibility
// =====================================

int main() {

    BST tree;

    // Insert books into BST
    tree.insert({ 105, "C++ Basics", "Ali" });
    tree.insert({ 50, "Data Structures", "Sara" });
    tree.insert({ 200, "Algorithms", "Omar" });
    tree.insert({ 250, "Computer Graphics", "Hassan" });
    tree.insert({ 300, "Deep Learning", "Mahmoud" });
    tree.insert({ 120, "Database Systems", "Mona" });
    tree.insert({ 30, "Operating Systems", "Ahmed" });
    tree.insert({ 75, "Networks", "Khaled" });
    tree.insert({ 10, "AI Basics", "Nour" });
    tree.insert({ 150, "Machine Learning", "Youssef" });
    tree.insert({ 90, "Cyber Security", "Salma" });

    // Display books in sorted order
    cout << "Books In-order:\n";
    tree.displayBooks();

    // Search for a specific book
    cout << "\n\nSearching for ID 120:\n";
    tree.searchBook(120);

    // Delete a book by ID
    cout << "\nDeleting Book ID 50...\n";
    tree.deleteBook(50);

    // Display books after deletion
    cout << "\nBooks after deletion:\n";
    tree.displayBooks();

    // Display tree height
    cout << "\nTree Height: "
        << tree.getHeight() << endl;

    // Find books within a specific ID range
    tree.findBooksInRange(70, 150);

    // Find closest book ID
    tree.findClosestBook(110);

    // =====================================
    // Sorted Input Test Case
    // Used to compare BST performance
    // =====================================

    BST testHeight;

    testHeight.insert({ 1, "A", "A" });
    testHeight.insert({ 2, "B", "B" });
    testHeight.insert({ 3, "C", "C" });
    testHeight.insert({ 4, "D", "D" });
    testHeight.insert({ 5, "E", "E" });
    testHeight.insert({ 6, "F", "F" });

    cout << "\nTest Height: "
        << testHeight.getHeight() << endl;

    return 0;
}
