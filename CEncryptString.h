#ifndef ENCRYPT_STRING_H
#define ENCRYPT_STRING_H

class CEncryptString
{
public:
    const char *String();
    CEncryptString(char * szCiphertext, unsigned int iLen, unsigned long ulKey, unsigned long ulMove);
    ~CEncryptString();

private:
    char *szPlaintext;
};

#endif // ENCRYPT_STRING_H