#include "PartOne.h"

namespace {
    const int MAX_RED = 12, MAX_GREEN = 13, MAX_BLUE = 14;
}


int PartOne::sumOfGames(std::ifstream& data) {
    int sumGameIDs = 0;
    std::string line;

    while(getline(data, line)) {
        bool countLine = true;
        while(line.find("red") != std::string::npos && countLine) {
            int index = line.find("red");
            line[index] = 'x';
            int amount = line[index-2] -48 + (isdigit(line[index-3]) ? (line[index-3]-48)*10 : 0);
            if(isdigit(line[index-4]) || amount > MAX_RED) countLine=false;
        }
        while(line.find("green") != std::string::npos && countLine) {
            int index = line.find("green");
            line[index] = 'x';
            int amount = line[index-2] -48 + (isdigit(line[index-3]) ? (line[index-3]-48)*10 : 0);
            if(isdigit(line[index-4]) || amount > MAX_GREEN) countLine=false;
        }
        while(line.find("blue") != std::string::npos && countLine) {
            int index = line.find("blue");
            line[index] = 'x';
            int amount = line[index-2] -48 + (isdigit(line[index-3]) ? (line[index-3]-48)*10 : 0);
            if(isdigit(line[index-4]) || amount > MAX_BLUE) countLine=false;
        }
        if(countLine) {
            int gameID = line[5] -48;
            int digitCheck = 6;
            while(isdigit(line[digitCheck])) {  // Could have done this way for colours too instead of the silly method above
                gameID = gameID*10 + line[digitCheck]-48;
                digitCheck++;
            }
            sumGameIDs += gameID;
        }
    }

    return sumGameIDs;
}

// ATTEMPT 1
/*  For each line, iterate over each colour and compare the number to MAX_
    Replace the colour with filler (e.g. "blue" -> "x") to find() next instance
    If no invalid subsets, add the gameId to the running total */
// int PartOne::sumOfGames(std::ifstream& data) {
//     int sumIDs = 0;
//     std::string line;

//     while(getline(data, line)) {
//         bool countGame = true;

//         // Checking number for each "blue"
//         while(line.find("blue") != std::string::npos && countGame) {
//             int index = line.find("blue");
//             line.replace(index, 1, "x");

//             int digits = 1;
//             while(isdigit(line[index-2-digits]))
//                 digits++;

//             int number = stoi(line.substr(index-2-digits, digits));
//             if(number > MAX_BLUE)
//                 countGame = false;
//         }

//         // Checking number for each "green"
//         while(line.find("green") != std::string::npos && countGame) {
//             int index = line.find("green");
//             line.replace(index, 1, "x");

//             int digits = 1;
//             while(isdigit(line[index-2-digits]))
//                 digits++;

//             int number = stoi(line.substr(index-2-digits, digits));
//             if(number > MAX_GREEN)
//                 countGame = false;
//         }

//         // Checking number for each "red"
//         while(line.find("red") != std::string::npos && countGame) {
//             int index = line.find("red");
//             line.replace(index, 1, "x");

//             int digits = 1;
//             while(isdigit(line[index-2-digits]))
//                 digits++;

//             int number = stoi(line.substr(index-2-digits, digits));
//             if(number > MAX_RED)
//                 countGame=false;
//         }

//         // Getting the Game ID
//         if(countGame) {
//             int gameId = stoi(line.substr(5, (line.find(":")-5)));
//             sumIDs += gameId;
//         }

//     }
//     return sumIDs;
// }