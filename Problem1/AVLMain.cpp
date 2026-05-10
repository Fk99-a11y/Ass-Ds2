#include "AVL.h"
#include <cstdlib>
#include <ctime>

int main() {
    AVL tree;
    srand(time(0));

    cout << "========== AVL TREE DEMONSTRATION ==========\n";

    // 1. Insert 15 random books
    cout << "\n1. Inserting 15 random books...\n";
    for (int i = 0; i < 15; i++) {
        int id = rand() % 300 + 1;
        Book b = {id, "Book_" + to_string(id), "Author_" + to_string(id % 10)};
        tree.insert(b);
    }

    // Insert fixed books for testing specific features
    tree.insert({105, "C++ Basics", "Ali"});
    tree.insert({50,  "Data Structures", "Sara"});
    tree.insert({200, "Algorithms", "Omar"});
    tree.insert({250, "Graphics", "Hassan"});
    tree.insert({300, "Deep Learning", "Mahmoud"});
    tree.insert({120, "Databases", "Mona"});
    tree.insert({30,  "Operating Systems", "Ahmed"});

    // 2. Display all books in sorted order
    cout << "\n2. In-order traversal (sorted by ID):\n";
    tree.displayBooks();

    // 3. Show tree height
    cout << "\n3. Tree height: " << tree.getHeight() << endl;

    // 4. Search for an existing ID
    cout << "\n4. Search for ID 120:\n";
    tree.searchBook(120);

    // 5. Search for a non-existing ID
    cout << "\n5. Search for non-existing ID 999:\n";
    tree.searchBook(999);

    // 6. Delete a book and show updated tree
    cout << "\n6. Delete ID 50:\n";
    tree.deleteBook(50);
    cout << "After deletion:\n";
    tree.displayBooks();

    // 7. Range search feature
    cout << "\n7. Range search [70 .. 150]:\n";
    tree.findBooksInRange(70, 150);

    // 8. Closest ID feature
    cout << "\n8. Find closest book to ID 110:\n";
    tree.findClosestBook(110);

    // ===== Sorted Input Test – demonstrates AVL stays balanced =====
    cout << "\n========== SORTED INPUT TEST ==========\n";
    AVL avlSorted;
    for (int i = 1; i <= 10; i++) {
        avlSorted.insert({i, "Sorted_" + to_string(i), "Author"});
    }
    cout << "Inserted IDs 1..10 in ascending order.\n";
    cout << "AVL Tree Height: " << avlSorted.getHeight()
         << " (logarithmic ~ log2(10) ~ 4)\n";
    cout << "In-order:\n";
    avlSorted.displayBooks();

    // Comparison note for the report
    cout << "\n========== COMPARISON (BST vs AVL) ==========\n";
    cout << "BST with same sorted input would have height = 10 (skewed).\n";
    cout << "AVL height = " << avlSorted.getHeight()
         << " -> remains balanced due to rotations.\n";

    return 0;
}