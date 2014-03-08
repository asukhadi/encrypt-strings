Runtime Encrypted Strings
===============
You can hide your strings from being easily extracted by encrypting them. They are decrypted at runtime and deleted when the object is destroyed.

Example
===============
```
String: asukhadi
EncryptString(("\x59\x1B\xBC\xE7\x7B\x53\x15\x99" + 0xF5326), 0xF5326, 8, 0x438).String()
```

How to encrypt the strings
===============
Encryption is Decryption (*minus the displacement*). Choose a random key and encrypt the string. Use the same initial key to decrypt.
```
void createEncryptString(char *szPlaintext, char *szCiphertext, unsigned int iLen, unsigned long *ulKey, unsigned long *ulMove)
{
    *ulKey = getRandom(100, 2000);
    *ulMove = getRandom(1000000, 2000000000);

    int key = *ulKey;

    // Encryption = Decryption
    for(int i = 0; i < iLen; i++)
    {
        szCiphertext[i] = (char)(szPlaintext[i] ^ key);
        key += key ^ (iLen ^ i);
    }
}
```