#include "Heap.h"

int main() {

    EmergencyHeap er;

    er.insertPatient({1, "Ahmed", 5, 1});
    er.insertPatient({2, "Sara", 9, 2});
    er.insertPatient({3, "Ali", 7, 3});
    er.insertPatient({4, "Mona", 9, 0});
    er.insertPatient({5, "Omar", 4, 4});

    er.displayPatients();

    er.viewNextPatient();

    er.treatNextPatient();

    er.displayPatients();

    er.updateSeverity(1, 10);

    er.displayPatients();

    return 0;
}
