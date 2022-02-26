// jsg vvmi mergong two shortest array and formatted array is also sorted ;
#include<iostream>
using namespace std;
void Merge_el(int a[],int n,int b[],int m,int c[]);
int main()
{
    int n,m,k=0,i,j;
    cout<<"\nplzz enter the size both array";
    cin>>n>>m;
    cout<<"\nplzz enter the elemenet of the 1 array:";
    int a[n],b[m],c[m+n];
    for(i=0;i<n;i++){cin>>a[i];}
    cout<<"\nplzz enter the elemenet of the 2 array:";
    for(i=0;i<m;i++){cin>>b[i];}
     Merge_el(a,n,b,m,c);
    for(i=0;i<m+n;i++){cout<<c[i]<<" ";}
}
void Merge_el(int a[],int n,int b[],int m,int c[])
{   int i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    for(;i<m;i++)
    {
        c[k++]=a[i];
    }
    for(;j<n;j++)
    {
        c[k++]=b[j];
    }
}
