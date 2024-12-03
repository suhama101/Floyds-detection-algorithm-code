#include <iostream>            // For cout
#include <chrono>              // For high_resolution_clock and timing utilities
#include <ctime>               // For time function (used in random_offset_experiment.cpp)

#include "cycle_experiment.h"
#include <vector>

using namespace std;

void runFixedOffsetExperiments(const vector<int>& listSizes, int fixedCycleStart, const vector<int>& cycleLengths, const string& filename) {
    for (int size : listSizes) {
        for (int cycleLength : cycleLengths) {
            Node* list = createLinkedListWithCycle(size, fixedCycleStart, cycleLength);
            int steps = 0;

            auto start = std::chrono::high_resolution_clock::now(); // Fully qualify with std::chrono
            bool hasCycle = detectCycle(list, steps);
            auto end = std::chrono::high_resolution_clock::now();   // Fully qualify with std::chrono

            long long time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // Fully qualify with std::chrono

            cout << "Fixed Offset -> List Size: " << size << ", Cycle Length: " << cycleLength 
                 << ", Steps: " << steps << ", Time: " << time << " microseconds\n";

            writeToCSV(filename, "Fixed Offset", size, fixedCycleStart, cycleLength, steps, time);

            deleteLinkedList(list);  // Free memory
        }
    }
}


