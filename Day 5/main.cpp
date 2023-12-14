#include "PartOne.cpp"

#include <iostream>

int main() {

    std::ifstream data;
    data.open("test1.txt");

    if(data.is_open()) {
        PartOne p1;
        int answer1 = p1.lowestLocation(data);
        std::cout << "Lowest relevant location number: " << answer1;
    }

    return 0;
}