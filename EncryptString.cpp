#include "EncryptString.h"

const char *EncryptString::String( ) 
{ 
    return szPlaintext;
}

EncryptString::EncryptString( char * szCiphertext, unsigned long ulMove, unsigned int iLen, unsigned long ulKey )
{
    szPlaintext = new char[iLen + 1];

    for(unsigned int i = 0 ; i < iLen ; i++)
    {
        szPlaintext[i] = (char)(szCiphertext[(i - ulMove)] ^ ulKey);
        ulKey += ulKey ^ (iLen ^ i);
    }

    szPlaintext[iLen] = '\0';
}

EncryptString::~EncryptString( )
{
    delete[] szPlaintext;
}