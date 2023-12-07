#include "PartOne.cpp"
#include "PartTwo.cpp"

#include <iostream>
#include <fstream>

int main() {

    std::ifstream data ("PuzzleInput.txt");

    // Part 1
    if(data.is_open()) {
        PartOne p1;
        int answer1 = p1.sumParts(data);
        std::cout << "Sum of all parts: " << answer1 << '\n';
    }

    // Reset stream to beginning
    data.clear();
    data.seekg(0);

    // Part 2
    if(data.is_open()) {
        PartTwo p2;
        int answer2 = p2.sumGearRatios(data);
        std::cout << "Sum of all gear ratios: " << answer2 << '\n';
    }


    return 0;
}