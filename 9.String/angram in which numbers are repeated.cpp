// jsg program to check string is anagram or not that all string made by same alphabet// when there is no duplicate el
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    cout<<"plzz enter your name\n";
    string s,t;
    int i;
    //cin>>s;
    getline(cin,s);
    getline(cin,t);
    int l=s.length();
    int m=t.length();
    //cout<<s.length()<<"\n";
   // cout<<t.length()<<"\n";
    cout<<s<<"\n";
    cout<<t<<"\n";

   if(m!=l){cout<<"not be anagram\n";}
   else
   {
   int Hash1[26]={0};
   int Hash2[26]={0};
   for(i=0;s[i];i++)
   {
       Hash1[s[i]-97]+=1;
   }
    for(i=0;t[i];i++)
   {
       Hash2[t[i]-97]+=1;
   }
   for(i=0;i<26;i++){cout<<Hash1[i]<<"\t";}
   cout<<"\n";
   for(i=0;i<26;i++){cout<<Hash2[i]<<"\t";}
   for(i=0;i<26;i++)
   {
       if(Hash1[i]!=Hash2[i])
       {
           cout<<"not be anagram\n";
           break;
       }
   }  if(i==26){cout<<"yes anagram\n";}
   }
}
