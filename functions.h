#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <cstdint>

void processOperation(const std::string& opcode, const std::vector<std::string>& operands);
std::string toHexString(uint32_t value);

#endif