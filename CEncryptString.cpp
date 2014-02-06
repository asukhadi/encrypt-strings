#include "CEncryptString.h"

const char *CEncryptString::String() 
{ 
    return szPlaintext;
}

CEncryptString::CEncryptString(char * szCiphertext, unsigned int iLen, unsigned long ulKey, unsigned long ulMove)
{
    szPlaintext = new char[iLen + 1];

    for(unsigned int i = 0 ; i < iLen ; i++)
    {
        szPlaintext[i] = (char)(szCiphertext[(i - ulMove)] ^ ulKey);
        ulKey += ulKey ^ (iLen ^ i);
    }

    szPlaintext[iLen] = '\0';
}

CEncryptString::~CEncryptString( void )
{
    delete[] szPlaintext;
}