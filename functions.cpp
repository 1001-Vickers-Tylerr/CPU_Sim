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
        
    }
}

std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}