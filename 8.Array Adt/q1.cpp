// jsf q1 dynamic array
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int *p,i,n;
    cout<<"plzz enter the size array\n";
    //here we creat a dynamic array
    cin>>n;
    p=new int [n*sizeof(int)];
    for(i=0;i<n;i++){cin>>p[i];}
    cout<<"\narray elements : \n";
     for(i=0;i<n;i++){cout<<p[i]<<" ";}
     // after that we have to release memory address
     delete[]p;
     p=NULL;

}
