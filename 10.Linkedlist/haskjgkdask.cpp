//jsg
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n\n"<<endl;
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }

}