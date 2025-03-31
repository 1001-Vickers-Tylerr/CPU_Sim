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

    uint32_t op1 = 0, 
             op2 = 0, 
             op3 = 0;

    if (operands.size() >= 1) {
        op1 = std::stoul(operands[0], nullptr, 16);
    }
    if (operands.size() >= 2) {
        op2 = std::stoul(operands[1], nullptr, 16);
    }
    if (operands.size() == 3) {
        op3 = std::stoul(operands[2], nullptr, 16);
    }

    switch (opcodeVal) {
        case 1: // ADD
            
            break;
        case 2: // SUB
            
            break;
        case 3: // CMP
            
            break;
        case 4: // MOV
            
            break;
        case 5: // AND
            
            break;
        case 6: // OR

            break;
        case 7: // XOR
            
            break;
        case 8: // LOAD
            
            break;
        case 9: // STORE
            
            break;
        case 10: // BAL
            
            break;
        case 11: // BEQ
            
            break;
        case 12: // BNE
            
            break;
        default:
            output += "Unsupported Operation";
            isValid = false;
            break;
    }

    std::cout << output << std::endl;
}

std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}