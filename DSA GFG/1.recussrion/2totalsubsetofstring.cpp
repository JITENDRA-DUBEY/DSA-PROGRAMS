#include<iostream>
#include<string.h>
using namespace std;
string t;
void subset(string s,string curr,int i)
{
      if(i==s.length())
      { cout<<curr<<",";
      return ;}
      subset(s,curr,i+1);// left side not include any char in curr;
      subset(s,curr+s[i],i+1);// include one by ine char from string
}
int main()
{
    string s="ABCD";
    subset(s,"",0);
  
}