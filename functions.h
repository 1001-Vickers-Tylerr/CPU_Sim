#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdint>
#include <string>

void processOperation(const std::string& opcode, const std::vector<std::string> &operands, std::vector<std::string> &registers, std::vector<std::string> &memory);
std::string toHexString(uint32_t value);

#endif