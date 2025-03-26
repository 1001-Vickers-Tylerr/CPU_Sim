#include "functions.h"
#include <iostream>
#include <vector>
#include <iomanip>

void processOperation(const std::string &opcode, const std::vector<std::string> &operands) {
    int a;
}

std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}