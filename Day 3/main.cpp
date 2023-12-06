#include "PartOne.cpp"

#include <iostream>
#include <fstream>

int main() {

    std::ifstream data ("PuzzleInput.txt");
    if(data.is_open()) {
        PartOne p1;
        int answer1 = p1.sumParts(data);
        std::cout << "Sum of all parts: " << answer1 << '\n';
    }

    return 0;
}