#include "Problem1/BST.h"
#include "Problem1/AVL.h"
#include "Problem2/Heap.h"

int main() {

    cout << "========== ANALYSIS ==========\n";

    // ================= BST =================
    BST bst;

    bst.insert({100, "Book1", "Ali"});
    bst.insert({50, "Book2", "Sara"});
    bst.insert({150, "Book3", "Omar"});
    bst.insert({75, "Book4", "Mona"});
    bst.insert({125, "Book5", "Ahmed"});

    cout << "\nBST Books:\n";
    bst.displayBooks();

    cout << "\nBST Search:\n";
    bst.searchBook(125);

    cout << "\nBST Range Search:\n";
    bst.findBooksInRange(60, 130);

    cout << "\nBST Closest ID:\n";
    bst.findClosestBook(120);

    cout << "\nBST Height: "
         << bst.getHeight() << endl;

    // ================= AVL =================
    AVL avl;

    avl.insert({100, "Book1", "Ali"});
    avl.insert({50, "Book2", "Sara"});
    avl.insert({150, "Book3", "Omar"});
    avl.insert({75, "Book4", "Mona"});
    avl.insert({125, "Book5", "Ahmed"});

    cout << "\nAVL Books:\n";
    avl.displayBooks();

    cout << "\nAVL Search:\n";
    avl.searchBook(125);

    cout << "\nAVL Range Search:\n";
    avl.findBooksInRange(60, 130);

    cout << "\nAVL Closest ID:\n";
    avl.findClosestBook(120);

    cout << "\nAVL Height: "
         << avl.getHeight() << endl;

    // ================= HEAP =================
    EmergencyHeap heap;

    heap.insertPatient({1, "Ahmed", 5, 1});
    heap.insertPatient({2, "Sara", 9, 2});
    heap.insertPatient({3, "Ali", 7, 3});

    cout << "\nHeap Patients:\n";
    heap.displayPatients();

    cout << "\nNext Patient:\n";
    heap.viewNextPatient();

    return 0;
}
