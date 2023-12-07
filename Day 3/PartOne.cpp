#include "PartOne.h"

#include <iostream>

int PartOne::sumParts(std::ifstream& data) {
    int sumOfParts = 0;

    // Storing the input data in a vector
    std::vector<std::string> engineSchematic;
    std::string line;
    while(getline(data, line)) {
        engineSchematic.push_back(line);    
    }
    
    // Iterating through each character
    for(int i = 0; i < engineSchematic.size(); i++) {
        int partNumber = 0;
        bool isPart = false;
        for(int j = 0; j < engineSchematic[i].size(); j++) {
            if(isdigit(engineSchematic[i][j])) {
                partNumber = (partNumber*10) + (engineSchematic[i][j] - '0');
                if(!isPart) isPart = checkSymbol(engineSchematic, i, j);
            }
            if((!isdigit(engineSchematic[i][j]) && partNumber > 0) || j == engineSchematic[i].size()-1) {
                if(isPart) {
                    sumOfParts += partNumber;
                    isPart = false;
                    // std::cout << partNumber << ' ';
                }
                partNumber = 0;
            }

        }
        // std::cout << '\n';
    }


    return sumOfParts;
}

bool PartOne::checkSymbol(std::vector<std::string>& v, int& i, int& j) {
    for(int row = i-1; row <= i+1; row++) {
        if(row >= 0 && row < v.size()) {
            for(int col = j-1; col <= j+1; col++) {
                if(col >= 0 && col < v[i].size())
                    if(!isdigit(v[row][col]) && v[row][col] != '.')
                        return true;
            }
        }
    }
    return false;
}