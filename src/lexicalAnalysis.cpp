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

        if (ch == '*' || ch == '/') {
            if (!globalBuffer.empty()) handleBufferContent();
            handleSLCPossibility(ch);
            handleMLCPossibility(ch);
            continue;
        }

        if (inSLCState || inMLCState) continue;

        if (!delayedBuffer.empty()) {
            globalBuffer = delayedBuffer;
            handleBufferContent();
            globalBuffer = delayedBuffer = "";
        }

        // If we still have
        if (!tempBufferMLC.empty()) tempBufferMLC = "";
        if (!tempBufferSLC.empty()) tempBufferSLC = "";

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
