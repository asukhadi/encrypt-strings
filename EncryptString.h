#ifndef ENCRYPT_STRING_H
#define ENCRYPT_STRING_H

class EncryptString
{
public:
    const char *String( );
	EncryptString( char * szCiphertext, unsigned long ulMove, unsigned int iLen, unsigned long ulKey );
    ~EncryptString( );

private:
    char *szPlaintext;
};

#endif // ENCRYPT_STRING_H