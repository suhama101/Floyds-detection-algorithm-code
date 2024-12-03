#ifndef CYCLE_EXPERIMENT_H
#define CYCLE_EXPERIMENT_H

#include <vector>
#include <string>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function declarations
Node* createLinkedListWithCycle(int size, int cycleStart, int cycleLength);
bool detectCycle(Node* head, int& steps);
void writeToCSV(const std::string& filename, const std::string& experimentType, int listSize, int cycleStart, int cycleLength, int steps, long long execTime);
void runFixedOffsetExperiments(const std::vector<int>& listSizes, int fixedCycleStart, const std::vector<int>& cycleLengths, const std::string& filename);
void runRandomOffsetExperiments(const std::vector<int>& listSizes, const std::vector<int>& cycleLengths, const std::string& filename);
void deleteLinkedList(Node* head);  // Function to delete the linked list

#endif  // CYCLE_EXPERIMENT_H
