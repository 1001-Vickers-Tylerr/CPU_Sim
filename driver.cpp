// Author: Tyler Vickers
// CS219 Programming Project 2

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "functions.h"

int main() {

    std::ifstream inputFile("pp2_input.txt");
    std::string line;

    if (!inputFile.is_open()) {
        std::cout << "Error opening input file\n";
        return 1;
    }

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> words;
        std::string word;

        while (iss >> word) {
            words.push_back(word);
        }

        if (words.empty()) continue;

        std::string opcode = words[0];
        std::vector<std::string> operands(words.begin() + 1, words.end());
        processOperation(opcode, operands);
    }

    return 0;
}