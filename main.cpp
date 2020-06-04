#include <iostream>
#include "include/errorCode.hpp"

extern "C" 
{
    #include "include/hello.h"
}


int 
main () {
    std::cout << "Hello\n";
    printGreeting();
    unsignError();
    return 0;
}