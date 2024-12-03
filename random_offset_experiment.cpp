#include <iostream>            // For cout
#include <chrono>              // For high_resolution_clock and timing utilities
#include <ctime>               // For time function (used in random_offset_experiment.cpp)

#include "cycle_experiment.h"
#include <vector>

using namespace std;

void runRandomOffsetExperiments(const vector<int>& listSizes, const vector<int>& cycleLengths, const string& filename) {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    for (int size : listSizes) {
        for (int cycleLength : cycleLengths) {
            int randomCycleStart = rand() % size + 1;  // Random cycle start between 1 and size
            Node* list = createLinkedListWithCycle(size, randomCycleStart, cycleLength);
            int steps = 0;

            auto start = std::chrono::high_resolution_clock::now(); // Fully qualify with std::chrono
            bool hasCycle = detectCycle(list, steps);
            auto end = std::chrono::high_resolution_clock::now();   // Fully qualify with std::chrono

            long long time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // Fully qualify with std::chrono

            cout << "Random Offset -> List Size: " << size << ", Cycle Length: " << cycleLength 
                 << ", Steps: " << steps << ", Time: " << time << " microseconds\n";

            writeToCSV(filename, "Random Offset", size, randomCycleStart, cycleLength, steps, time);

            deleteLinkedList(list);  // Free memory
        }
    }
}


