#include <iostream>
#include <fstream>
#include <map>

int main() {

    std::map<std::string, int> opcodeMap = {
        {"ADD", 1},
        {"SUB", 2},
        {"AND", 3},
        {"OR", 4},
        {"XOR", 5},
        {"NOT", 6},
        {"LSL", 7},
        {"LSR", 8},
        {"EQ", 9},
        {"LT", 10},
        {"GT", 11}
    };

    std::ifstream inputFile;
    std::string line;

    inputFile.open("pp1_input.txt");

    while (std::getline(inputFile, line)) {

    }

    return 0;
}