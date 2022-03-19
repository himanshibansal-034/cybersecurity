#include <iostream>
#include <string>
using namespace std;

string generateKey(string msg, string keyWord){
    int sizeKeyword = keyWord.size();
    int msgSize = msg.size(); 
    if(sizeKeyword > msgSize){
        return keyWord.substr(0, msgSize);
    }
    for(int i=sizeKeyword; i<msg.size(); i++){
        keyWord.push_back(keyWord[i%sizeKeyword]);
    }
    return keyWord;
}
string encryption(string msg, string key) {
    string output;
    for(int i=0; i<msg.size(); i++){
        char x = (msg[i] + key[i]) % 26; 
        if(msg[i] == ' ')
            x = ' ';
        else
            x = x + 'A';
        output.push_back(x);
    }
    return output;
}
string decryption(string encrypt, string key) {
    string output;
    int j=0;
    for (int i=0; i<encrypt.size(); i++) {
        char x = (encrypt[i] - key[i] + 26) % 26;
        if(encrypt[i] == ' ')
            x = ' ';
        else
            x = x + 'A';
        output.push_back(x);
    }
    return output;
}

int main() {
        string keyWord,msg;
        cout<<"Enter the message to be ciphered: \n";
        getline(cin,msg);
        cout<<"Enter the key: \n";
        cin>>keyWord;
        string key = generateKey(msg, keyWord);
        string encrypt = encryption(msg, key);
        string decrypt = decryption(encrypt, key);
        cout<<"Generated Key is: "<<key<<endl;
        cout<<"Encrypted Cipher Text: "<<encrypt<<endl;
        cout<<"Decrypted Plain Text: "<<decrypt;
    return 0;
}