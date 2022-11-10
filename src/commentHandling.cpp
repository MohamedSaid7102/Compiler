#include "../include/headers.h"

void resetSLCState() {
    inSLCState = false;
    isSLCFirstSlashExists = false;
}

void handleIfLastStateWasNotComment() {
    // if we had that first slash, but now we have something other than '/'
    // or '*', so last slash was a division operator '/'
    if(isSLCFirstSlashExists) {
        isHandledAsOperator('/');
        resetSLCState();
    }
}

void handleSLCPossibility() {
    if (!isSLCFirstSlashExists)
        isSLCFirstSlashExists = true;
    else
        inSLCState = true;
}