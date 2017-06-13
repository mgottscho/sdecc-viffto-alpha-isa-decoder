/*
 * Author: Mark Gottscho
 * Email: mgottscho@ucla.edu
 */

#include "MyDecoder.hh"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdint.h>

#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    /*if(nrhs != 1) {
            mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs",
                                  "One input required.");
    }
    if(nlhs != 1) {
            mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs",
                                  "One output required.");
    }*/

    /* make sure the first input argument is a string */
    /*if( !mxIsString(prhs[0]) || 
                  mxGetNumberOfElements(prhs[0]) != 1 ) {
            mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notString",
                                  "Input must be a string.");
    }*/
    

    //redirect stdout
    std::stringstream outputStream;
    std::cout.rdbuf(outputStream.rdbuf());

    //Get raw input
    char inputCharString[9];
    mxGetString(prhs[0], inputCharString, 9);
    inputCharString[8] = '\0';
    std::string instString(inputCharString);
    std::cout << "Raw input: " << instString << std::endl;

    //Switch little to big endian on input string
    std::string after(instString);
    after.replace(0,2,instString.substr(6,2));
    after.replace(2,2,instString.substr(4,2));
    after.replace(4,2,instString.substr(2,2));
    after.replace(6,2,instString.substr(0,2));

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
    } else {
        std::cout << "valid" << std::endl;
    }

    double* output = NULL;
    plhs[0] = mxCreateDoubleMatrix(1,1,mxREAL);
    plhs[1] = mxCreateString(outputStream.str().c_str());
    output = mxGetPr(plhs[0]);
    if (ret)
        *output = 1;
    else
        *output = 0;
}
