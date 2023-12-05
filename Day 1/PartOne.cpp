#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string line;
    std::ifstream data ("data.txt");

    if(data.is_open()) {
        long long answer = 0;

        while(getline(data, line)) {
            int first = -1;
            int last = -1;
            for(const char& c : line) {
                if(!isdigit(c))
                    continue;
                if(first==-1) {
                    first = c -48;
                    last = c -48;
                } else {
                    last = c -48;
                }
            }
            answer += first*10 + last;
        }
        
        data.close();
        std::cout << "The sum of all calibration values is: " << answer << '\n';
    }
    
    return 0;
}