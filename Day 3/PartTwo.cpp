#include "PartTwo.h"

#include <iostream>
#include <unordered_map>

namespace {
    std::unordered_map<std::string, std::vector<int>> gearPartMap; // string is gear coordinate, int is partNumber/s
    std::string gearCoordinate = ""; // used to store gear coordinate
}

int PartTwo::sumGearRatios(std::ifstream& data) {
    // Translating data into vector engineSchematic
    std::vector<std::string> engineSchematic;
    std::string line;
    while(getline(data, line))
        engineSchematic.push_back(line);

    // Population gearPartMap with parts touching a gear and their corresponding gear coordinate
    for(int row = 0; row < engineSchematic.size(); row++) {
        int partNumber = 0;
        bool isGear = false;
        for(int col = 0; col < engineSchematic[row].size(); col++) {
            if(isdigit(engineSchematic[row][col])) {
                partNumber = partNumber*10 + engineSchematic[row][col] - '0';
                isGear = isGear || checkSymbol(engineSchematic, row, col);
            }
            if(!isdigit(engineSchematic[row][col]) || col == engineSchematic[row].size()-1) {
                if(partNumber && isGear) {
                    gearPartMap[gearCoordinate].push_back(partNumber);
                    gearCoordinate = "";
                    isGear = false;
                }
                partNumber = 0;
            }
        }
    }

    // From gearPartMap, getting the gear ratios of gear coordinates with 2 partNumbers
    int sumGearRatios = 0;
    for(const auto& pair : gearPartMap) {
        if(pair.second.size() == 2)
            sumGearRatios += pair.second[0]*pair.second[1];
    }
    return sumGearRatios;
}

bool PartTwo::checkSymbol(std::vector<std::string>& v, int& i, int& j) {
    if(gearCoordinate != "") return false;
    for(int di = i-1; di <= i+1; di++) {
        if(di >= 0 && di < v.size()) {
            for(int dj = j-1; dj <= j+1; dj++) {
                if(dj>=0 && dj<=v[di].size()) {
                    if(v[di][dj] == '*') {
                        gearCoordinate += std::to_string(di) + 'a' + std::to_string(dj);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}