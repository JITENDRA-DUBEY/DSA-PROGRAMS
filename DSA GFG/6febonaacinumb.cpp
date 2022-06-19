#include<iostream>
using namespace std;
#include<vector>
vector<int>ans;
int feb(int n)
{
    if(n<2)
   { return n;}
    else
    {int x=feb(n-1);
     int x2=feb(n-2);
     
     return feb(n-1)+feb(n-2);}
}
int main()
{    for(int i=1;i<=5;i++)
      ans.push_back(feb(i));
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<"suss";
}