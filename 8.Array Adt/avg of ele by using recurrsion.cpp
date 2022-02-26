// jsg sum of array element by using recurrsion;
#include<iostream>
#include<math.h>
using namespace std;
int avgel(int a[],int n);
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
     l=avgel(a,n);
     cout<<"\nsum = :"<<avgel(a,n);
     avg=(l/(n*(1.0)));// because int/int is not float
     cout<<"\navg : "<<avg;
}
int avgel(int a[],int n)
{
    int s;
    if(n==0){return 0;}
    else
        return avgel(a,n-1)+a[n-1];

}
