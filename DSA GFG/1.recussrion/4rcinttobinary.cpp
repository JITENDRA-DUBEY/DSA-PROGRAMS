#include<iostream>
using namespace std;
void decimaltobinary(int n)
{
    if(n==0)// terminating cond
    return ;
    decimaltobinary(n/2); 
   cout<<n%2;
   
}
int main()
{
    decimaltobinary(18);
    cout<<"\nsucc";
}