#include <bits/stdc++.h>
using namespace std;

void shiftn(vector<int> &arr, int a)
{
    for (int i = arr.size() - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = a;
}

int main()
{
    string s;
    cout << "Enter string to be encrypted : ";
    getline(cin, s);
    vector<int> x = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    vector<int> y = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    vector<int> z = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    string key;
    for (int i = 0; i < s.size(); i++)
    {
        int num = 0;
        for (int j = 6; j >= 0; j--)
        {
            int mj = (x[8] + y[10] + z[10] > 1 ? 1 : 0); 
            if (mj == x[8])
                shiftn(x, x[18] ^ x[17] ^ x[16] ^ x[13]);

            if (mj == y[10])
                shiftn(y, y[21] ^ y[20]);

            if (mj == z[10])
                shiftn(z, z[22] ^ z[21] ^ z[20]);

            num = num * 2 + (x[18] ^ y[21] ^ z[22]);
        }
        key += char(num);
    }
    string enc;
    for (int i = 0; i < s.size(); i++)
        enc += s[i] ^ key[i];
    cout << "Encrypted string is :" << enc << endl;

    string dec;
    for (int i = 0; i < s.size(); i++)
        dec += enc[i] ^ key[i];
    cout << "Decrypted string is : " << dec;
}