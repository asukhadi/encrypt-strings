#include "Create.h"

int main()
{
	srand(time(0));

	unsigned int iLen = 13;
	unsigned long ulKey = 0, ulMove = 0;
    char* cipher = new char[iLen];

	createEncryptString("EncryptString", cipher, iLen, &ulKey, &ulMove);
	
	printf("String: %s\n", CEncryptString((cipher + ulMove), iLen, ulKey, ulMove).String());
	printf("CEncryptString((\"%s\" + 0x%X), %d, 0x%X, 0x%X).String()\n", toHex(cipher, iLen), ulMove, iLen, ulKey, ulMove);

	delete[] cipher;

    return 0;
}

void createEncryptString(char *szPlaintext, char *szCiphertext, unsigned int iLen, unsigned long *ulKey, unsigned long *ulMove)
{
    *ulKey = getRandom(100, 2000);
    *ulMove = getRandom(1000000, 2000000000);

	int key = *ulKey;

    for(int i = 0; i < iLen; i++)
    {
        szCiphertext[i] = (char)(szPlaintext[i] ^ key);
        key += key ^ (iLen ^ i);
    }
}

int getRandom(int start, int end)
{
    return rand() % end + start;
}

char* toHex(char* buffer, int len)
{
	char *hex = new char[len*4];
	int length = 0;

	for ( int i = 0; i < len; i++ ) 
	{
		length += sprintf( hex + length, "\\x%02X", (unsigned char) buffer[i] );
	}

	return hex;
}