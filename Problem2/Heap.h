#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

using namespace std;

struct Patient {
    int id;
    string name;
    int severity;
    int arrivalTime;
};

class EmergencyHeap {

private:

    vector<Patient> heap;

    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);

    bool higherPriority(Patient a, Patient b);

    void heapifyUp(int index);
    void heapifyDown(int index);

public:

    void insertPatient(Patient p);

    void treatNextPatient();

    void viewNextPatient();

    void updateSeverity(int id, int newSeverity);

    void displayPatients();
};

#endif
