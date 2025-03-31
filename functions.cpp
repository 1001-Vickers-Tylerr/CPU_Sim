#include "functions.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

void processOperation(const std::string &opcode, const std::vector<std::string> &operands, std::vector<std::string> &registers, std::vector<std::string> &memory) {
    uint32_t result;
    bool isValid = true;
    std::string output = opcode + " ";
    for (const std::string & op : operands) {
        output += op + " ";
    }
    output += ": ";

    std::map<std::string, int> opcodeMap = {
        {"ADD", 1}, {"SUB", 2}, {"CMP", 3}, {"MOV", 4}, {"AND", 5}, {"OR", 6},
        {"XOR", 7}, {"LOAD", 8}, {"STORE", 9}, {"BAL", 10}, {"BEQ", 11}, {"BNE", 12}
    };

    // Convert to opcode to mapping value, if doesn't exist -> 0
    int opcodeVal;
    if (opcodeMap.find(opcode) != opcodeMap.end()) {
        opcodeVal = opcodeMap[opcode];
    } 
    else {
        opcodeVal = 0;
    }

    if ((opcodeVal > 0 && opcodeVal <= 2) || (opcodeVal > 4 && opcodeVal <= 7)) {
        if (operands.size() != 3) {
            std::cout << output << "Invalid Operation Count\n";
            return;
        }
    }
    else if ((opcodeVal > 2 && opcodeVal <= 3) || (opcodeVal > 7 && opcodeVal <= 9)) {
        if (operands.size() != 2) {
            std::cout << output << "Invalid Operation Count\n";
            return;
        }
    }
    else if (opcodeVal > 9 && opcodeVal <= 12) {
        if (operands.size() != 1) {
            std::cout << output << "Invalid Operation Count\n";
            return;
        }
    }
    else {
        std::cout << output << "Unsupported opcode";
    }

}

std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}