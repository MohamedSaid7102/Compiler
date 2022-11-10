#include "include/headers.h"
#include <stdexcept>
#include <iostream>


int main() {
    /**
     * Important Notes:
     * SLC: Single Line Comment
     * MLC: Multi  Line Comment
     */
    try {
        // Phase 1.0
        lexicalAnalysis("testingSourceCode.cpp");
    } catch (const std::runtime_error& e) {
        std::cout<<e.what();
    }
    return 0;
}
