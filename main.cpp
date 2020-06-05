#include <iostream>
#include "include/errorCode.hpp"

extern "C" 
{
    #include "include/hello.h"
}

extern int i;   // declares but does not define i
int j;          // declares and defines j

int 
main () {
    printGreeting();

    int units_sold1 = 0;
    int units_sold2 = {0};
    int units_sold3{0};
    int units_sold4(0);

    std::cout << "units_sold1 : " << units_sold1 << "\n";
    std::cout << "units_sold2 : " << units_sold2 << "\n";
    std::cout << "units_sold3 : " << units_sold3 << "\n";
    std::cout << "units_sold4 : " << units_sold4 << "\n";

    long double ld = 3.1415926536;
    //int a{ld}, b = {ld}; // error: narrowing conversion required
    int c(ld), d = ld;   // ok: but value will be truncated

    std::cout << "c : " << c << "\n";
    std::cout << "d : " << d << "\n";

    // std::cout << "i : " << i << "\n";
    std::cout << "j : " << j << "\n";

    int ival = 42;
    int *p = &ival;
    int &rval = ival;
    std::cout << "p\t: " << p << "\n";
    std::cout << "*p\t: " << *p << "\n";
    std::cout << "rval\t: " << rval << "\n";
    std::cout << "&rval\t: " << &rval << "\n";

    return 0;
}