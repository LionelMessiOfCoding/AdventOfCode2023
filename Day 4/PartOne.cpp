#include "PartOne.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cmath>

int PartOne::TotalPoints(std::ifstream& data) {
    int totalPoints = 0;
    // Get data in vector, from first number to last number (inclusive)
    std::vector<std::string> cards;
    std::string line;
    while(getline(data, line)) {
        cards.push_back(line.substr(line.find(":")+2, line.size()-line.find(":")-2) + " ");
    }

    // For each line: Get the left numbers in a map, count the right numbers that are in left, add points
    for(int i = 0; i < cards.size(); i++) {
        // Left numbers
        std::unordered_map<int, int> winningNumbers;
        int number = 0;
        for(int j = 0; j < cards[i].find('|'); j++) {
            if(isdigit(cards[i][j]))
                number = number*10 + cards[i][j] -'0';
            else if(number > 0) {
                winningNumbers[number]++;
                number = 0;
            }
        }

        // Right numbers
        int count = 0;
        for(int j = cards[i].find('|')+2; j < cards[i].size(); j++) {
            if(isdigit(cards[i][j]))
                number = number*10 + cards[i][j] -'0';
            else {
                if(winningNumbers.find(number) != winningNumbers.end())
                    count++;
                number = 0;
            }
        }

        // Add points
        totalPoints += int(pow(2, count-1));
    }
    
    

    return totalPoints;
}