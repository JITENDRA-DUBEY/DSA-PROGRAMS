// jsg vvmi negative number on left side and positive number on ryt side
#include<math.h>
#include<iostream>
using namespace std;
void Arrange_list(int a[],int n);
int main()
{
    int i,key,l,n;
    float avg;
    cout<<"\nplzz enter the size of array";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    // for linear search
    Arrange_list(a,n);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}
void Arrange_list(int a[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        while(a[i]<0){i++;}
        while(a[j]>=0){j--;}
        if(i<j)
        swap(a[i],a[j]);
    }
}
