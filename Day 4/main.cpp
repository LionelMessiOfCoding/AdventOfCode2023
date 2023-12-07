#include "PartOne.cpp"
#include "PartTwo.cpp"

#include <iostream>

int main() {

    std::ifstream data;
    data.open("PuzzleInput.txt");

    // Part One
    if(data.is_open()) {
        PartOne p1;
        int answer1 = p1.TotalPoints(data);
        std::cout << "Total points: " << answer1 << '\n';
    }

    data.clear();
    data.seekg(0);

    if(data.is_open()) {
        PartTwo p2;
        int answer2 = p2.TotalPoints(data);
        std::cout << "Total scratchcards: " << answer2;
    }

    return 0;
}