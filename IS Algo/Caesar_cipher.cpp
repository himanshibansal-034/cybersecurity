#include<iostream>
using namespace std;
string encrypt_message(string str_message,int key)
{
    char ch;
    int j;
   for(j = 0; str_message[j] != '\0'; j++)
   {
        ch = str_message[j];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            str_message[j] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            str_message[j] = ch;
        }
    }
    return str_message;
}
string decrypt_message(string str_message,int key)
{
    char ch;
    int j;
    for(j = 0; str_message[j] != '\0'; j++)
    {
        ch = str_message[j];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if(ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            str_message[j] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if(ch > 'a')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            str_message[j] = ch;
        }
    }
    return str_message;
}

int main()
{
  string str_message,choice;
  int key;
  cout << "Enter a message to encrypt: ";
  cin>>str_message;
  cout << "Enter key: ";
  cin >> key;
  string enc_ans=encrypt_message(str_message,key);
  cout << "Encrypted Cipher Text: " << enc_ans<<endl;
  string decr_ans=decrypt_message(enc_ans,key);
  cout<< "Decrypted Plain Text: "<<decr_ans<<endl;
  return 0;
}