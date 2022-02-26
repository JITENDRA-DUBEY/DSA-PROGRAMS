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
   int Hash[26];
   for(i=0;s[i];i++)
   {
       Hash[s[i]-97]+=1;
   }
   for(i=0;i<26;i++)
   {
       if(Hash[t[i]-97]==0)
       {
           cout<<"not be anagram\n";
           break;
       }
   }  if(i==26){cout<<"yes anagram\n";}
   }
}
