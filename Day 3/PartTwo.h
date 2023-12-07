#ifndef PARTTWO_H_
#define PARTTWO_H_

#include <fstream>
#include <vector>

class PartTwo {
public:
    int sumGearRatios(std::ifstream&);
    bool checkSymbol(std::vector<std::string>&, int&, int&);
};

#endif /* PARTTWO_H_ */


// Namespace:
//      gearPartMap<string, vec<int>>:
//          - Key: gearCoordinate - contains the coordinates of a gear('*'), separated by 'a', as a string.
//            e.g. if there is a '*' at [15,4] touching a number, key value is "15a4"
//          - Value: partNumber(s) - contains all partNumbers touching the gear at gearCoordinate

// sumGearRatios():
//      Stores each line in a vector<string>
//      Does the following for each line:
//          - int partNumber = 0, bool isGear = false
//          - When a number is found:
//                  > Adds it as the right-most digit of partNumber
//                  > calls checkSymbol() on that position, and updates isGear accordingly
//          - When a non-number is found:
//                  > If partNumber > 0 (i.e. there is a number stored), adds it to gearPartMap
//                    and resets (partNumber = 0, isGear = false, gearCoordinate = "") for the next number
//          - When the end of the line is reached and it's a number, also calls checkSymbol() etc. (Important for edge case with number at end)

// checkSymbol():
//      - Checks for a '*' symbol directly around the given point, in the bounds of vec.size()/vec[i].size()
//      - Used in sumGearRatios() to update isGear
//      - Updates gearCoordinate with coordinate, e.g. if '*' is at [5, 24], gearCoordinate = "5a24"