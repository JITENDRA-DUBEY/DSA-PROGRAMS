#include<iostream>
#include<string.h>
using namespace std;
string t;
void rev(string s,int st,int e)
{
      if(e<0)
      return ;
      if(st<=e)
      {
         t.push_back(s[e]);
          rev(s,st,e-1);
      }
}
int main()
{
    string s="jite";
    rev(s,0,4);
    cout<<t;
}