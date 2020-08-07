#include <iostream>
#include <map>
#include "include/errorCode.hpp"

extern "C" 
{
    #include "include/hello.h"
}

extern int i;   // declares but does not define i
int j;          // declares and defines j

void ch1and2 () {

    // int i; 
    // const int size1 = i; 
    // constexpr int size2 = i;


    // int errNumb = 0;
    // int *const curErr = &errNumb;  // curErr will always point to errNumb
    // ++errNumb;
    // ++(*curErr);
    // std::cout << "*curErr\t: " << *curErr << "\n";

    // char* initptr = 0;
    // char* otherptr = 0;
    // const pointer
    // char * const constptr = initptr;
    // *constptr = 1;              // 改變其 value OK
    // constptr = otherptr;        // 改變其  addr Error
    // 
    // const value
    // const char * constval = "const value";
    // *constval = "nomal value";  // 改變其 value Error
    // constval = otherptr;        // 改變其  addr OK
    // 
    // const pointer & const value
    // const char * const consteverything = "ulti - const";

    // typedef struct data {
    //     int a;
    //     int b;
    // }data;
    // 
    // int price;
    // data myData;
    // std::cin >> myData.a >> myData.b >> price;
    // std::cout << "myData.a\t: " << myData.a << "\n";
    // std::cout << "myData.b\t: " << myData.b << "\n";
    // std::cout << "price\t: "    << price << "\n";
}

void ch3 () {
    // std::string s1 = "hello", s2 = "world"; // no punctuation in s1 or s2
    // std::string s3 = s1 + ", " + s2 + '\n';
    // std::string s4 = s1 + ", ";             // ok: adding a string and a literal
    // std::string s5 = "hello" + ", ";        // error: no string operand
    // std::string s6 = s1 + ", " + "world";   // ok: each + has a string operand
    // std::string s7 = "hello" + ", " + s2;   // error: can't add string literals

    // process characters in s until we run out of characters or we hit a whitespace
    std::string s("some string");
    for (decltype(s.size()) index = 0;index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]); // capitalize the currentcharacter
}

int 
main () {
    printGreeting();
    std::map<int, int, int> qwert;
    qwert[0] = 1;

    return 0;
}  