#include "cycle_experiment.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

// Create linked list with a cycle at a given starting point
Node* createLinkedListWithCycle(int size, int cycleStart, int cycleLength) {
    Node* head = new Node(1);
    Node* temp = head;
    Node* cycleNode = nullptr;

    for (int i = 2; i <= size; i++) {
        temp->next = new Node(i);
        temp = temp->next;
        if (i == cycleStart) cycleNode = temp;
    }

    // Create the cycle
    Node* tail = temp;
    for (int i = 1; i < cycleLength && tail; i++) {
        tail = tail->next;
    }
    if (tail) {
        tail->next = cycleNode;
    }

    return head;
}

// Detect cycle and count steps
bool detectCycle(Node* head, int& steps) {
    Node* slow = head;
    Node* fast = head;
    steps = 0;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        steps++;
        if (slow == fast) return true;  // Cycle detected
    }
    return false;
}

// Write results to CSV file
void writeToCSV(const string& filename, const string& experimentType, int listSize, int cycleStart, int cycleLength, int steps, long long execTime) {
    ofstream file;
    file.open(filename, ios::app);  // Open in append mode
    file << experimentType << "," << listSize << "," << cycleStart << "," << cycleLength << "," << steps << "," << execTime << "\n";
    file.close();
}

// Delete linked list to free memory
void deleteLinkedList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
