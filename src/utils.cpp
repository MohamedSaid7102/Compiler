#include <iostream>
#include <fstream>
#include "../include/headers.h"


// Functions
bool isKeyword(std::string buffer)
{
//    if(commentState) return false;
    const int KEYWORDS_SIZE = 35;
    std::string keywords[KEYWORDS_SIZE] =
            {"auto", "break", "main", "case", "char", "const", "continue", "default",

             "do", "double", "else", "enum", "extern", "float", "for", "goto",

             "if", "int", "long", "register", "return", "short", "signed",

             "sizeof", "static", "struct", "switch", "union",
             "unsigned", "void", "volatile", "while","std","cout","cin"};

    for (int i = 0; i < KEYWORDS_SIZE; ++i)
        if (keywords[i] == buffer)
            return true;

    return false;
}

bool isHandledAsOperator(char ch) {
    const int OPERATOR_SIZE=7;
    std::string operators[OPERATOR_SIZE][2] = {{"/", "division"},{"+","plus"}, {"-","minus"},
                                               {"*","multiplication"},
                                               {"%","modules"},{"=", "equal"},{":","colon"}};

    for (int i = 0; i < OPERATOR_SIZE; ++i)
        if (ch == operators[i][0][0]) {
            if (!globalBuffer.empty()) handleBufferContent();
            std::cout << "\" " << ch << " \"" << " is operator\n";
            return true;
        }

    return false;
}

bool isHandledAsSpecial(char ch) {
    handleIfLastStateWasNotComment();

    const int SPECIALS_SIZE=16;

    std::string specials[SPECIALS_SIZE] = {"(",")","$","#","@","!","`","\"","\'",".",",","{","}","<",">",";"} ;
    for (int i = 0; i < SPECIALS_SIZE; ++i)
        if (ch == specials[i][0]){
            if (!globalBuffer.empty()) handleBufferContent();
            std::cout << "\" " << ch << " \"" << " is a special character\n";
            return true;
        }
    return false;
}

bool isHandledAsCharOrNumber(char ch) {
    handleIfLastStateWasNotComment();

    if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9') || (ch >= 0 && ch <= 9)) {
        globalBuffer += ch;
        return true;
    }
    return false;
}

void handleBufferContent() {
    if (isKeyword(globalBuffer))
        std::cout <<"\" "<<globalBuffer<<" \"" << " is keyword\n";
    else
        std::cout <<"\" "<<globalBuffer<<" \"" << " is identifier\n";
    globalBuffer= "";
}

// File Utilities
std::ifstream handleFileOpening(std::string sourceCodeFileName){
    std::ifstream fileHandler;
    fileHandler.open(sourceCodeFileName); // You will find this file in 'cmake-build-debug/'

    if (!fileHandler.is_open())
        throw std::runtime_error("There is no such file, please check and try again ..!\n");

    return fileHandler;
}