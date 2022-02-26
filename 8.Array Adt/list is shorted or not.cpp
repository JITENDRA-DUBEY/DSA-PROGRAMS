// jsg here we list is sorted in ascending order or not by comparing the adjacent element;
#include<math.h>
#include<iostream>
using namespace std;
void Sort_list(int a[],int n);
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
    Sort_list(a,n);

}
void Sort_list(int a[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            cout<<"\nno";
            break;
        }
    }
    if(i==n-1)
    cout<<"\nyes";
}
