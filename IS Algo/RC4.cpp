#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter the string to be encrypted: ";
    getline(cin, str);
    string key;
    cout << "Enter the key : ";
    getline(cin, key);
    int s[256], t[256];
    int i;

    // generates repeated key elements
    for (i = 0; i < 256; i++)
    {
        s[i] = i;
        t[i] = key[i % key.size()]; 
    }

    // key scheduling
    int j = 0;
    for (i = 0; i < 256; i++)
    {
        j = (j + s[i] + t[i]) % 256;
        swap(s[i], s[j]);
    }

    // keystream generation
    string keystream;
    i = j = 0;
    for (int k = 0; k < str.size(); k++)
    {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        swap(s[i], s[j]);
        int k1 = s[(s[i] + s[j]) % 256];
        keystream += char(k1);
    }

    string enc;
    for (i = 0; i < str.size(); i++)
        enc += str[i] ^ keystream[i];
    cout << "Encrypted Cipher Text : " << enc << endl;

    string dec;
    for (i = 0; i < str.size(); i++)
        dec += keystream[i] ^ enc[i];
    cout << "Decrypted Plain Text : " << dec;
}