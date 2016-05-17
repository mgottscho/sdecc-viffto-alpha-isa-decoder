#include "MyDecoder.hh"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdint.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: alphadecode <INST>" << std::endl;
        std::cout << "where <INST> is a 64-bit ALPHA instruction specified in hexadecimal format, e.g., 0xDEADBEEFDEADBEEF." << std::endl;
        return 1;
    }

    uint64_t raw;

    std::stringstream ss;
    std::string instString(argv[1]);
    ss << std::hex << instString;
    ss >> raw;

    std::cout << "Raw input: " << instString << std::endl;
    std::cout.fill('0');
    std::cout << "Interpreted as: 0x" << std::hex << std::setw(16) << raw << std::dec << std::endl;
    std::cout.fill(' ');
    
    AlphaISA::ExtMachInst inst = static_cast<AlphaISA::ExtMachInst>(raw);

    AlphaISA::Decoder decoder;
    std::cout << "Disassembly: ";
    bool ret = decoder.decodeInst(inst);
    std::cout << "Result: ";
    if (ret) {
        std::cout << "ILLEGAL" << std::endl;
        return ret;
    } else {
        std::cout << "valid" << std::endl;
        return ret;
    }
}
