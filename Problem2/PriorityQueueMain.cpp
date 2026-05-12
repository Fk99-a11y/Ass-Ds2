#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Patient {

    int id;
    string name;
    int severity;
    int arrivalTime;
};

struct ComparePatients {

    bool operator()(Patient a, Patient b) {

        if (a.severity == b.severity)
            return a.arrivalTime > b.arrivalTime;

        return a.severity < b.severity;
    }
};

int main() {

    priority_queue<
        Patient,
        vector<Patient>,
        ComparePatients
    > pq;

    pq.push({1, "Ahmed", 5, 1});
    pq.push({2, "Sara", 9, 2});
    pq.push({3, "Ali", 7, 3});
    pq.push({4, "Mona", 9, 0});

    cout << "Patients Treatment Order:\n\n";

    while (!pq.empty()) {

        Patient p = pq.top();

        cout << "ID: " << p.id
             << " | Name: " << p.name
             << " | Severity: " << p.severity
             << " | Arrival Time: " << p.arrivalTime
             << endl;

        pq.pop();
    }

    return 0;
}
