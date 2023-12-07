#include <iostream>
#include <fstream>

#include "PartOne.cpp"
#include "PartTwo.cpp"

int main() {

    std::ifstream data("PuzzleInput.txt");
    
    // This block outputs the answer for part 1
    if(data.is_open()) {
        PartOne p1;
        int partOneAnswer = p1.sumOfGames(data);
        std::cout << "The sum of all valid game IDs is " << partOneAnswer << '\n';
    }
    
    // Reset stream to beginning for Part 2
    data.clear();   // Clears any error flags
    data.seekg(0);  // Moves pointer back to beginning of file

    // This block outputs the answer for part 2
    if(data.is_open()) {
        PartTwo p2;
        int partTwoAnswer = p2.sumOfPowers(data);
        std::cout << "The sum of the powers is " << partTwoAnswer << '\n';
        data.close();
    }

    return 0;
}