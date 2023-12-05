#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {

    std::unordered_map<std::string, std::string> word_numbers = 
    {
        {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"},
        {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}
    };

    std::ifstream data ("data.txt");
    std::string line;

    if(data.is_open()) {
        int answer = 0;
        // Find all occurrences of word_numbers in line and replace second char with digit
        // Iterate over line and get first/last digit
        while(getline(data, line)) {
            for(const auto& pair : word_numbers) {
                if(line.find(pair.first) == std::string::npos) // find() returns npos if not found
                    continue;
                int word_index = line.find(pair.first);
                line.replace(word_index+1, 1, pair.second);

                if(line.rfind(pair.first) == std::string::npos)
                    continue;
                word_index = line.rfind(pair.first);
                line.replace(word_index+1, 1, pair.second);
            }
            
            int first = -1, last = -1;

            for(int i = 0; i < line.size(); i++) {
                if(!isdigit(line[i]))
                    continue;
                if(first == -1) {
                    first = line[i] -48;
                    last = line[i] -48;
                } else {
                    last = line[i] -48;
                }
            }

            
            answer += first*10 + last;
        }
        data.close();
        std::cout << "The sum of all calibration values is " << answer;
    }

    return 0;
}