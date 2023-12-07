#include "PartTwo.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cmath>

// Basically same as Part 1, except added repetitions
int PartTwo::TotalPoints(std::ifstream& data) {
    // Get data in vector, from first number to last number (inclusive)
    std::vector<std::string> cards;
    std::string line;
    while(getline(data, line)) {
        cards.push_back(line.substr(line.find(":")+2, line.size()-line.find(":")-2) + " ");
    }

    // Track total card count and repetitions per card
    int totalCards = 0;
    int n = cards.size();
    int repetitions[n];
    std::fill(repetitions, repetitions + n, 1);


    // For each line: Get the left numbers in a map, count the right numbers that are in left, add points, add repetitions
    for(int i = 0; i < cards.size(); i++) {
        // Repeat this line repetitions[i] times
        for(int repeat = 0; repeat < repetitions[i]; repeat++) {
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

            // Calculate repetitions
            for(int di = 1; di <= count && di + i < cards.size(); di++)
                repetitions[di+i]++;
        }
    }

    // Add total repetitions to get totalCards - could also just totalCards++ in above loop
    for(const int& r : repetitions)
        totalCards += r;

    return totalCards;
}