#include<bits/stdc++.h>
using namespace std;

string encrypt(string text,int r,int c,vector<int>&r_p,vector<int>&c_p){
	string result="";
	int n=text.size();

	vector<vector<char>>matrix(r,vector<char>(c,' '));
    int p=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(p<n)
                matrix[i][j]=text[p++];
            else
                matrix[i][j]='#';
        }
    }

    vector<vector<char>>changed_matrix(r,vector<char>(c,' '));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            changed_matrix[i][j]=matrix[r_p[i]-1][j];
        }
    }

    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            matrix[j][i]=changed_matrix[j][c_p[i]-1];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result+=matrix[i][j];
        }
    }

	return result;
}


string decrypt(string cypher_text,int r,int c,vector<int>&r_p,vector<int>&c_p){
	string result="";
	int n=cypher_text.size();

    vector<vector<char>>matrix(r,vector<char>(c,' '));
    int p=0;
    for(int i=0;i<r && p<n;i++){
        for(int j=0;j<c;j++){
            matrix[i][j]=cypher_text[p++];
            if(p==n)
                break;
        }
    }

    vector<vector<char>>changed_matrix(r,vector<char>(c,' '));
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            changed_matrix[j][c_p[i]-1]=matrix[j][i];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            matrix[r_p[i]-1][j]=changed_matrix[i][j];
        }
    }    

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]!='#')
                result+=matrix[i][j];
        }
    }

    return result;
}

int32_t main()
{
    string text;
    cout<<"Enter text to be ciphered: ";
    cin>>text;
    int r,c;
    cout<<"Enter no of rows and column : ";
    cin>>r>>c;
    vector<int>r_p(r);
    cout<<"Enter row permutation : ";
    for(int i=0;i<r;i++)
        cin>>r_p[i];
    vector<int>c_p(c);
    cout<<"Enter column permutation : ";
    for(int i=0;i<c;i++)
        cin>>c_p[i];
    

    string result;
    result=encrypt(text,r,c,r_p,c_p);
    cout<<"\nEncrypted Cipher Text :"<<result;
    result=decrypt(result,r,c,r_p,c_p);
    cout<<"\nDecrypted Plain Text :"<<result;
    return 0;
}