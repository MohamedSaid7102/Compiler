//
// Created by shelf on 11/10/22.
//
#include <string>

#ifndef SHELMAACOMPILER_HEADERS_H
#define SHELMAACOMPILER_HEADERS_H
//Variables
inline std::string globalBuffer = "";
inline std::string tempBufferSLC = "";
inline std::string tempBufferMLC = "";
inline std::string delayedBuffer = "";
inline bool inSLCState = false;
inline bool inMLCState = false;

//Functions ---------------------------------
// 1.Lexical --------------------------------
void lexicalAnalysis(std::string);

// 1.1 Comments Handling --------------------
void resetSLCState();

void resetMLCState();

void handleSLCPossibility(char ch);

void handleMLCPossibility(char ch);

void handleIfLastStateWasNotComment();

// 1.2 Lexical util functions
bool isKeyword(std::string buffer);

bool isHandledAsOperator(char ch);

bool isHandledAsSpecial(char ch);

bool isHandledAsCharOrNumber(char ch);

void handleBufferContent();

// File handling
std::ifstream handleFileOpening(std::string sourceCodeFileName);

#endif //SHELMAACOMPILER_HEADERS_H
