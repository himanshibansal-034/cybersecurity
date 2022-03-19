#include<bits/stdc++.h>
using namespace std;
string key="abcde";
vector<int> mask;
map<char,int > m={
    {'a',0} , {'b',1} , {'c',2} , {'d',3} , {'e',4}
    , {'f',5}, {'g',6}, {'h',7}, {'i',8}, {'j',9}
    , {'k',10}, {'l',11}, {'m',12}, {'n',13}, {'o',14}
    , {'p',15}, {'q',16}, {'r',17}, {'s',18}, {'t',19}
    , {'u',20}, {'v',21}, {'w',22}, {'x',23}, {'y',24}
    , {'z',25}
};

string encrypt(string s, string key)
{
    string res;
    int i=0,j=0;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    
    s = regex_replace(s,regex("\\s+"), "");
    for( auto x: s)
    {
        int k = (((m[x]^m[key[i]])));
        if(k>=26)
          mask.push_back(1);
        else
          mask.push_back(0);
        ans.push_back(k%26);
        j++;  i++;
        if(i==key.length())
          i=0;
    }
    for(auto x:ans)
    {
        char c=x+97;
        res+=c;
    }
    return res;
}

string decrypt(string s, string key)
{
    string res;
    vector<int> ans;
    int i=0,j=0;
    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);

    s = regex_replace(s,regex("\\s+"), "");
    for( auto x: s)
    {
        if(mask[j]==1)
          ans.push_back((((m[x]+26)^m[key[i]])));
        else if(mask[j]==0)
          ans.push_back(((m[x]^m[key[i]])));
        i++;j++;
        if(i==key.length())
          i=0;
    }
    for(auto x:ans)
    {
        char c=x+97;
        res+=c;
    }
    return res;
}

bool auth(string k,string msg)
{
    string enc = encrypt(msg,k);
    string dec = decrypt(enc,k);
    if(msg == dec)
        return true;
    return false;
}

int main(){
    string s;
    string r1,r2;
    r1="hello";
    r2="howareyou";
    bool f1 = auth(key,r1);
    bool f2 = auth(key,r2);
    if(f1 and f2)
        cout<<"authentication successfull"<<endl;
    else if(!f1 and f2)
        cout<<"authentication failed, only user y have been identified"<<endl;
    else if(f1 and !f2)
        cout<<"authentication failed, only user x have been identified"<<endl;
    else
        cout<<"authentication faled"<<endl;
    
    return 0;
}