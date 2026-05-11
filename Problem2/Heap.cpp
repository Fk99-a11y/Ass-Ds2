#include "Heap.h"

int EmergencyHeap::parent(int i) {
    return (i - 1) / 2;
}

int EmergencyHeap::leftChild(int i) {
    return 2 * i + 1;
}

int EmergencyHeap::rightChild(int i) {
    return 2 * i + 2;
}

bool EmergencyHeap::higherPriority(Patient a, Patient b) {

    if (a.severity != b.severity)
        return a.severity > b.severity;

    return a.arrivalTime < b.arrivalTime;
}

void EmergencyHeap::heapifyUp(int index) {

    while (index > 0 &&
           higherPriority(heap[index], heap[parent(index)])) {

        swap(heap[index], heap[parent(index)]);

        index = parent(index);
    }
}

void EmergencyHeap::heapifyDown(int index) {

    int highest = index;

    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap.size() &&
        higherPriority(heap[left], heap[highest])) {

        highest = left;
    }

    if (right < heap.size() &&
        higherPriority(heap[right], heap[highest])) {

        highest = right;
    }

    if (highest != index) {

        swap(heap[index], heap[highest]);

        heapifyDown(highest);
    }
}

void EmergencyHeap::insertPatient(Patient p) {

    heap.push_back(p);

    heapifyUp(heap.size() - 1);

    cout << "Patient inserted successfully.\n";
}

void EmergencyHeap::treatNextPatient() {

    if (heap.empty()) {

        cout << "No patients in emergency room.\n";
        return;
    }

    cout << "\nTreating Patient:\n";

    cout << "ID: " << heap[0].id << endl;
    cout << "Name: " << heap[0].name << endl;
    cout << "Severity: " << heap[0].severity << endl;
    cout << "Arrival Time: " << heap[0].arrivalTime << endl;

    heap[0] = heap.back();

    heap.pop_back();

    if (!heap.empty())
        heapifyDown(0);
}

void EmergencyHeap::viewNextPatient() {

    if (heap.empty()) {

        cout << "No patients in emergency room.\n";
        return;
    }

    Patient p = heap[0];

    cout << "\nNext Patient:\n";

    cout << "ID: " << p.id << endl;
    cout << "Name: " << p.name << endl;
    cout << "Severity: " << p.severity << endl;
    cout << "Arrival Time: " << p.arrivalTime << endl;
}

void EmergencyHeap::updateSeverity(int id, int newSeverity) {

    for (int i = 0; i < heap.size(); i++) {

        if (heap[i].id == id) {

            int oldSeverity = heap[i].severity;

            heap[i].severity = newSeverity;

            if (newSeverity > oldSeverity)
                heapifyUp(i);

            else
                heapifyDown(i);

            cout << "Severity updated successfully.\n";

            return;
        }
    }

    cout << "Patient not found.\n";
}

void EmergencyHeap::displayPatients() {

    if (heap.empty()) {

        cout << "No patients in emergency room.\n";
        return;
    }

    cout << "\nAll Patients (Level Order):\n\n";

    for (Patient p : heap) {

        cout << "ID: " << p.id
             << " | Name: " << p.name
             << " | Severity: " << p.severity
             << " | Arrival Time: " << p.arrivalTime
             << endl;
    }
}
