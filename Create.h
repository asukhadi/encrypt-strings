#ifndef CREATE_H
#define CREATE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include "CEncryptString.h"

using namespace std;

void createEncryptString(char *szPlaintext, char *szCiphertext, unsigned int iLen, unsigned long *ulKey, unsigned long *ulMove);
int getRandom(int start, int end);
char* toHex(char* buffer, int len);

#endif // CREATE_H