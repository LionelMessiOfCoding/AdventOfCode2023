#include "PartOne.cpp"

#include <iostream>

int main() {

    std::ifstream data;
    data.open("PuzzleInput.txt");

    if(data.is_open()) {
        PartOne p1;
        int answer1 = p1.TotalPoints(data);
        std::cout << "Total points: " << answer1;
    }

    return 0;
}