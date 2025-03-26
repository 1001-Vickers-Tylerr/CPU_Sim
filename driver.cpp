// Author: Tyler Vickers
// CS219 Programming Project 2

#include <iostream>
#include <fstream>
#include <vector>
#include "functions.h"

int main() {

    std::ifstream inputFile("pp2_input.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cout << "Error opening input file\n";
        return 1;
    }

    return 0;
}