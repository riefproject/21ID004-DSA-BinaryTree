#ifndef MORSE_H
#define MORSE_H
#include "binarytree.h"
int charToMorse(BinTree root, int target, char* path, int depth);
char MorseToChar(BinTree root, char* path);
void MorseStringToText(BinTree root, const char* morseInput, char* output);
#endif
