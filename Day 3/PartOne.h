#ifndef PARTONE_H_
#define PARTONE_H_

#include <fstream>
#include <vector>

class PartOne {
public:
    int sumParts(std::ifstream&);
    bool checkSymbol(std::vector<std::string>&, int&, int&);
};

#endif /* PARTONE_H_ */


// sumParts():
//      Stores each line in a vector<string>
//      Does the following for each line:
//          - int partNumber = 0, bool isPart = false
//          - When a number is found:
//                  > Adds it as the right-most digit of partNumber
//                  > calls checkSymbol() on that position, and updates isPart accordingly
//          - When a non-number is found:
//                  > If partNumber > 0 (i.e. there is a number stored), adds it if isPart
//                    and resets partNumber = 0, isPart = false (for the next number)
//          - When the end of the line is reached and it's a number, also calls checkSymbol() etc. (Important for edge case with number at end)

// checkSymbol():
//      - Checks for a symbol around the given point
//      - Used in sumParts() to update isPart