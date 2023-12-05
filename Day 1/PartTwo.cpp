#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {

    std::unordered_map<std::string, int> word_numbers = 
    {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    std::ifstream data ("data.txt");
    std::string line;

    if(data.is_open()) {
        int answer = 0;
        // Get the first/last digit values as before, as well as their respective index
        // Find all occurrences of word_numbers in line and compare index
        while(getline(data, line)) {
            int first = -1, last = -1, first_index = -1, last_index = -1;

            for(int i = 0; i < line.size(); i++) {
                if(!isdigit(line[i]))
                    continue;
                if(first == -1) {
                    first = line[i] -48;
                    first_index = i;
                    last = line[i] -48;
                    last_index = i;
                } else {
                    last = line[i] -48;
                    last_index = i;
                }
            }

            for(const auto& pair : word_numbers) {
                if(line.find(pair.first) == std::string::npos) // find() returns npos if not found
                    continue;
                int word_index = line.find(pair.first);
                if(word_index < first_index) {
                    first = pair.second;
                    first_index = word_index;
                }
                if(line.rfind(pair.first) == std::string::npos) continue;
                word_index = line.rfind(pair.first);
                if(word_index > last_index) {
                    last = pair.second;
                    last_index = word_index;
                }
            }

            answer += first*10 + last;
        }
        data.close();
        std::cout << "The sum of all calibration values is " << answer;
    }

    return 0;
}