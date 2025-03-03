#include "functions.h"
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <map>

void processOperation(const std::string& opcode, const std::vector<std::string>& operands) {
    uint32_t result;
    bool isValid = true;
    std::string output = opcode + " ";
    for (const auto& op : operands) {
        output += op + " ";
    }
    output += ": ";

    std::map<std::string, int> opcodeMap = {
        {"ADD", 1}, {"SUB", 2}, {"AND", 3}, {"OR", 4}, {"XOR", 5},
        {"NOT", 6}, {"LSL", 7}, {"LSR", 8}, {"EQ", 9}, {"LT", 10}, {"GT", 11}
    };

    int opcodeVal;
if (opcodeMap.find(opcode) != opcodeMap.end()) {
    opcodeVal = opcodeMap[opcode];
} else {
    opcodeVal = 0;
}

    // Check operand count first
    if ((opcodeVal >= 1 && opcodeVal <= 5) || (opcodeVal >= 7 && opcodeVal <= 11)) { // Binary operations
        if (operands.size() != 2) {
            std::cout << output << "Invalid Operand Count\n";
            return;
        }
    } else if (opcodeVal == 6) { // NOT
        if (operands.size() != 1) {
            std::cout << output << "Invalid Operand Count\n";
            return;
        }
    }

    // Note for me: std::stoul() is a function that converts a string
    // into an unsigned long integer
    uint32_t op1 = 0, op2 = 0;
    if (operands.size() >= 1) {
        op1 = std::stoul(operands[0], nullptr, 16);
    }
    if (operands.size() == 2) {
        op2 = std::stoul(operands[1], nullptr, 16);
    }

    switch (opcodeVal) {
        case 1: // ADD
            result = op1 + op2;
            output += "0x" + toHexString(result);
            break;

        case 2: // SUB
            result = op1 - op2;
            output += "0x" + toHexString(result);
            break;

        case 3: // AND
            result = op1 & op2;
            output += "0x" + toHexString(result);
            break;

        case 4: // OR
            result = op1 | op2;
            output += "0x" + toHexString(result);
            break;

        case 5: // XOR
            result = op1 ^ op2;
            output += "0x" + toHexString(result);
            break;

        case 6: // NOT
            result = ~op1;
            output += "0x" + toHexString(result);
            break;

        case 7: // LSL
            if (static_cast<int32_t>(op2) < 0) {
                output += "Negative shift count";
                isValid = false;
            } else if (op2 >= 32) {
                output += "Shift Value Exceeds Bit Size";
                isValid = false;
            } else {
                result = op1 << op2;
                output += "0x" + toHexString(result);
            }
            break;

        case 8: // LSR
            if (static_cast<int32_t>(op2) < 0) {
                output += "Negative shift count";
                isValid = false;
            } else if (op2 >= 32) {
                output += "Shift Value Exceeds Bit Size";
                isValid = false;
            } else {
                result = op1 >> op2;
                output += "0x" + toHexString(result);
            }
            break;

        case 9: // EQ
            output += (op1 == op2) ? "true" : "false";
            break;

        case 10: // LT
            output += (op1 < op2) ? "true" : "false";
            break;

        case 11: // GT
            output += (op1 > op2) ? "true" : "false";
            break;

        default:
            output += "Unsupported Operation";
            isValid = false;
            break;
    }
    
    std::cout << output << std::endl;
}

// Converting uint32t to hex, helper function
std::string toHexString(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}