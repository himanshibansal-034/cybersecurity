//alic pri, pub key
// digit sign= encrytpt msg using private key of Alice
// send Digital sign to Bob 
// bob decrypt using public key of alice 

#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>

using namespace std;

int temp[50];
char val[50];
char en[50];
char m[50];
long int e[50],d[50];
int arr[3];

int prime(long int pr)
{
   int i;
   int j = sqrt(pr);
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

 long int cd(long int a,long int t)
{
   long int k = 1;
   while(1)
   {
      k = k + t;
      if(k % a == 0)
         return(k/a);
   }
}

//function to generate encryption key
void encryption_key(int x,int y,int *arr)
{
   
   int k;
   k = 0;
   int flag;
   int n=x*y;
   long int t=(x-1)*(y-1);
   for(int i = 2; i < t; i++)
   {
      if(t % i == 0)
         continue;
      flag = prime(i);
      if(flag == 1 && i != x && i != y)
      {
         e[k] = i;
         flag = cd(e[k],t);
         if(flag > 0)
         {
            d[k] = flag;
            k++;
         }
         if(k == 99)
         break;
      }
   }
   arr[0]=e[0];
   arr[1]=d[0];
   arr[2]=n;
   
}




char* encrypt(char* msg,int key, int n)
{
   
   long int pt, ct, k, len;
   int i = 0;
    len = strlen(msg);
   
   
   while(i != len)
   {
      pt = msg[i];
      pt = pt - 96;
      k = 1;
      for(int j = 0; j < key ; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct= k + 96;
      en[i] = ct;
      i++;
   }
   en[i] = -1;
  
   return en;
}

//function to decrypt the message
char* decrypt(char* msg,int key, int n)
{
  
   long int pt, ct, k;
   int i = 0;
   
   while(msg[i] != -1)
   {
      ct = temp[i];
      k = 1;
      for(int j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
   }
   m[i] = -1;
 
  return m;
}

bool auth(char* msg,int pub,int priv,int n)
{
   
    for(int i=0; msg[i]!='\0';i++)
      val[i] = msg[i];
   char enc[50];
   strcpy(enc,encrypt(val,priv,n)); //this is digital sign of Alice 
   char d[50];
   strcpy(d,decrypt(enc,pub,n)); 
  
   for(int i=0;msg[i]!='\0';i++)
      if( msg[i] != d[i])
         return false;
   return true;
}


int main(){

int p1,q1,p2,q2;   
int keyX[3];
cout<<"Enter two Prime no for key generation of User X"<<endl;
cin>>p1>>q1;
char r1[]="hello";

encryption_key(p1,q1,keyX); // key generation of X

bool a1=auth(r1,keyX[0],keyX[1],keyX[2]);  //autheciation of digital sign
cout<<endl;
if(a1)
cout<<"Digital signature is verified and This means that Alice has Send the msg noone else"<<endl;
else
cout<<"verification failed msg has not been sent by alice"<<endl;
cout<<endl;
}