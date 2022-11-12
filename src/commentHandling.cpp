#include "../include/headers.h"

void resetSLCState() {
    tempBufferSLC = "";
    inSLCState = false;
}

void resetMLCState() {
    tempBufferMLC = "";
    inMLCState = false;
}

void handleSLCPossibility(char ch) {
    if (ch != '/' || inMLCState) {
        resetSLCState();
        return;
    }

    tempBufferSLC += ch;

    if (tempBufferSLC == "//") {
        inSLCState = true;
        tempBufferSLC = delayedBuffer = "";
        resetMLCState();
    }
}

void handleMLCPossibility(char ch) {
    if (ch != '/' && ch != '*' || inSLCState) return;

    tempBufferMLC += ch;

    if (tempBufferMLC == "/*") {
        inMLCState = true;
        tempBufferMLC = delayedBuffer = "";
        resetSLCState();
        return;
    }

    if (tempBufferMLC == "*/") {
        resetMLCState();
        resetSLCState();
        return;
    }

    // Otherwise
    if (!inMLCState)
        delayedBuffer += ch;

    if (tempBufferMLC.size() > 1)
        tempBufferMLC = tempBufferMLC.back();

}
