// jsg sum of array element by using recurrsion;
#include<iostream>
#include<math.h>
using namespace std;
int sumel(int a[],int n);
int main()
{
    int n,i,key;
    cout<<"\nplzz enter the size of array";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // for linear search
    cout<<"\nSum : "<<sumel(a,n);
}
int sumel(int a[],int n)
{
    int s;
    if(n==0){return 0;}
    else
        return sumel(a,n-1)+a[n-1];

}
