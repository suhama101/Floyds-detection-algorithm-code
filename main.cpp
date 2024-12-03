#include "cycle_experiment.h"
#include <vector>
#include <fstream>

using namespace std;
int main() {
    // EVEN values
// SMALL VALUES
// vector<int> listSizes={100,200,300}; 
// vector<int> cycleLengths = {10,15,20}; 
// vector<int> fixedCycleStarts = {20,50,100}; 
//  MEDIUM VALUES
// vector<int> listSizes={1000, 2000, 3000};
// vector<int> cycleLengths = {50,75,100}; 
// vector<int> fixedCycleStarts = {200,500,1000};  
// LARGE VALUES
// vector<int> listSizes={22000, 20000, 30000};
// vector<int> cycleLengths = {200,300,400}; 
// vector<int> fixedCycleStarts = {2500, 5000, 7500};
// EXTRA LARGE
// vector<int> listSizes={100000, 200000,300000};
// vector<int> cycleLengths = {1000, 2000,5000}; 
// vector<int> fixedCycleStarts = {25000,50000,100000};
    //   ODD VALUES
    // SMALL VALUES
// vector<int> listSizes = {33, 199, 301}; 
// vector<int> cycleLengths = {9, 15, 21}; 
// vector<int> fixedCycleStarts = {10, 20, 30}; 
    //  MEDIUM VALUES
// vector<int> listSizes = {355, 2001, 3001};
// vector<int> cycleLengths = {49, 75, 101}; 
// vector<int> fixedCycleStarts = {100, 300, 350};
    //   LARGE VALUES
// vector<int> listSizes = {22001, 20003, 30007};
// vector<int> cycleLengths = {199, 301, 401}; 
// vector<int> fixedCycleStarts = {2000, 5000, 7000};
        // EXTRA LARGE
vector<int> listSizes = {100001, 200003, 300011};
vector<int> cycleLengths = {1001, 2001, 5001}; 
vector<int> fixedCycleStarts = {25000, 50000, 75000}; 






// Prepare CSV filenames for output
    string fixedFilename = "fixed_offset_results.csv";
    string randomFilename = "random_offset_results.csv";

 // Write headers for CSV files
    ofstream fixedFile(fixedFilename);
    fixedFile << "Experiment Type,List Size,Cycle Start,Cycle Length,Steps,Execution Time (microseconds)\n";
    fixedFile.close();

    ofstream randomFile(randomFilename);
    randomFile << "Experiment Type,List Size,Cycle Start,Cycle Length,Steps,Execution Time (microseconds)\n";
    randomFile.close();

 // Run experiments for each fixed cycle start position
    for (int fixedStart : fixedCycleStarts) {
        runFixedOffsetExperiments(listSizes, fixedStart, cycleLengths, fixedFilename);
    }
    
 // Run experiments for random offsets (with multiple trials)
    for (int i = 0; i < 5; i++) {  // Run 5 trials for each combination
        runRandomOffsetExperiments(listSizes, cycleLengths, randomFilename);
    }

    return 0;
}
