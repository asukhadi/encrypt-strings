#include "Create.h"

int main()
{
	// Set seed here -> A time seed is not recommended for repeated uses of rand()
	srand(time(0));

	unsigned int iLen = 8;
	unsigned long ulKey = 0, ulMove = 0;
	char* cipher = new char[iLen];

	// Creating the ciphertext from plaintext and retrieving the key + move
	createEncryptString("asukhadi", cipher, iLen, &ulKey, &ulMove);
	
	// Testing the ciphertext and outputting the call
	printf("String: %s\n", CEncryptString((cipher + ulMove), iLen, ulKey, ulMove).String());
	printf("CEncryptString((\"%s\" + 0x%X), %d, 0x%X, 0x%X).String()\n", toHex(cipher, iLen), ulMove, iLen, ulKey, ulMove);

	delete[] cipher;
	return 0;
}

void createEncryptString(char *szPlaintext, char *szCiphertext, unsigned int iLen, unsigned long *ulKey, unsigned long *ulMove)
{
	// Generating random key + move
	*ulKey = getRandom(100, 2000);
	*ulMove = getRandom(1000000, 2000000000);

	// We need to save the key to a different variable, because it changes for each loop iteration
	int key = *ulKey;

	// Encryption = Decryption
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
		length += sprintf(hex + length, "\\x%02X", (unsigned char) buffer[i]);
	}

	return hex;
}