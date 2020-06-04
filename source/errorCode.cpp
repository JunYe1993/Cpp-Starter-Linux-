#include "errorCode.hpp"

void unsignError() {
    // WRONG: u can never be less than 0; the condition will always succeed
    for (unsigned u = 10; u >= 0; --u)
        std::cout << u << std::endl;
}