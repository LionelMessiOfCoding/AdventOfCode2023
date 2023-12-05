#include "PartTwo.h"

#include <iostream>
#include <cmath>
#include <algorithm>

int PartTwo::sumOfPowers(std::ifstream& data) {
    int powersSum = 0;
    std::string line;

    while(getline(data, line)) {
        int max_red = 0, max_green = 0, max_blue = 0;
        // Checking one colour at a time
        while(line.find("red") != std::string::npos) {
            int index = line.find("red");
            line[index] = 'x';
            index-=2;
            int amount = line[index] -48, digits = 1;
            while(isdigit(line[index-digits])) {
                amount += (line[index-digits]-48)*pow(10,digits);
                digits++;
            }
            max_red = std::max(max_red, amount);
        }
        while(line.find("green") != std::string::npos) {
            int index = line.find("green");
            line[index] = 'x';
            index-=2;
            int amount = line[index] -48, digits = 1;
            while(isdigit(line[index-digits])) {
                amount += (line[index-digits]-48)*pow(10,digits);
                digits++;
            }
            max_green = std::max(max_green, amount);
        }
        while(line.find("blue") != std::string::npos) {
            int index = line.find("blue");
            line[index] = 'x';
            index-=2;
            int amount = line[index] -48, digits = 1;
            while(isdigit(line[index-digits])) {
                amount += (line[index-digits]-48)*pow(10,digits);
                digits++;
            }
            max_blue = std::max(max_blue, amount);
        }

        powersSum += max_red*max_green*max_blue;
    }

    return powersSum;
}