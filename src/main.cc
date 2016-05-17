#include "MyDecoder.hh"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdint.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: alphadecode <INST>" << std::endl;
        std::cout << "where <INST> is a 32-bit ALPHA instruction specified in LITTLE-ENDIAN hexadecimal format, e.g., 0xDEADBEEF." << std::endl;
        return 1;
    }
    
    //Get raw input
    std::string instString(argv[1]);
    std::cout << "Raw input: " << instString << std::endl;
    
    //Switch little to big endian on input string
    std::string after(instString);
    after.replace(2,2,instString.substr(8,2));
    after.replace(4,2,instString.substr(6,2));
    after.replace(6,2,instString.substr(4,2));
    after.replace(8,2,instString.substr(2,2));

    //Use the converted value
    std::stringstream ss;
    uint32_t raw;
    ss << std::hex << after;
    ss >> raw;

    std::cout.fill('0');
    std::cout << "Interpreted as: 0x" << std::hex << std::setw(8) << raw << std::dec << " (internal little to big endian conversion)" << std::endl;
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
