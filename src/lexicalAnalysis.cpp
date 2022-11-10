#include <iostream>
#include <stdexcept>
#include <fstream>
#include "../include/headers.h"

void lexicalAnalysis(std::string sourceCodeFileName) {

    std::ifstream fileHandler = handleFileOpening(sourceCodeFileName);
    char ch = '\0';

    while (!fileHandler.eof()) {
        ch = fileHandler.get();

        // in case of newline
        if (ch == '\n' && inSLCState) {
            resetSLCState();
            continue;
        }

        if (inSLCState) continue;

        /* handle 1 line comment first */
        if (ch == '/') {
            tempBufferItems[tempBufferItemsPointer++] = ch;
            handleSLCPossibility();
            continue;
        }

        if (isHandledAsOperator(ch)) continue;
        if (isHandledAsSpecial(ch)) continue;
        if (isHandledAsCharOrNumber(ch)) continue;

        if (ch == ' ' || ch == '\0') {
            if (globalBuffer.empty()) continue;
            handleBufferContent();
            continue;
        }
    }
    // if the buffer is not empty handle it's content
    if (!globalBuffer.empty()) handleBufferContent();
}
