// reverse an array by a->b,b->a,a->b;#include<iostream>
#include<math.h>
#include<iostream>
using namespace std;
void Swap(int a[],int n);
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
     Swap(a,n);
         for(i=0;i<n;i++)
        {
        cout<<a[i]<<"\t";
        }
}
void Swap(int a[],int n)
{
    int b[n],temp,i;
    for(i=0;i<n;i++)
     {
        b[i]=a[(n-1)-i];
     }
     for(i=0;i<n;i++)
     {
        a[i]=b[(n-1)-i];
     }
}
