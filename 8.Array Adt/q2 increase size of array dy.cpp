// jsf q1 dynamic array
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int *p,*q,i,n,nz;
    cout<<"plzz enter the size array\n";
    //here we creat a dynamic array
    cin>>n;
    p=new int [n*sizeof(int)];
    for(i=0;i<n;i++){cin>>p[i];}
    cout<<"\narray elements : \n";
     for(i=0;i<n;i++){cout<<p[i]<<" ";}
     // after that we have to release memory address
     cout<<"plzz enter new size array\n";
     cin>>nz;
     q=new int [nz*sizeof(int)];
     for(i=0;i<n;i++){q[i]=p[i];}
     delete[]p;// for avoiding memeory leakage release memmeroy because we already copied
     // that array in new array;
     p=q;// assigning the address of new array in p now p pointing new size array
     q=NULL;// so that now q is not dangling
     cout<<"\nenter more ele";
     for(i=n;i<nz;i++)
     {
         cin>>p[i];
     }
      for(i=0;i<nz;i++){cout<<p[i]<<" ";}
     delete []p;
     p=NULL;
}




