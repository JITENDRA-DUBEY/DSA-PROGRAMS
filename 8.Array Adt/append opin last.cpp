// jsg q1 dynamic array for appending first we have to increase the size of array
//by 1 by taking new array q;
#include<iostream>
#include<conio.h>
using namespace std;
void app(int *r,int sz,int x);
int main()
{
    int *p,*q,i,n;
    cout<<"plzz enter the size array\n";
    //here we creat a dynamic array
    cin>>n;
    p=new int [n*sizeof(int)];
    for(i=0;i<n;i++){cin>>p[i];}
    cout<<"\narray elements : \n";
     for(i=0;i<n;i++){cout<<p[i]<<" ";}
     q=new int [(n+1)*sizeof(int)];
     for(i=0;i<n;i++){q[i]=p[i];}
     delete[]p;
     p=q;
     q=NULL;
    app(p,n+1,10);
    cout<<"\n";
    for(int i=0;i<n+1;i++){cout<<p[i]<<" ";}
     delete []p;
     p=NULL;
}
void app(int *r,int sz,int x)
{
    r[sz-1]=x;
    //for(int i=0;i<sz;i++){cout<<r[i]<<" ";}
}



