// jsg here i want to insert a elelement at givewn
//index so fpr that array size should be enough#include<iostream>
// here we assume that their is already vacant space in the given array
#include<conio.h>
#include<iostream>
using namespace std;
void Insert(int *r,int sz,int i,int x);
int main()
{
    int i,n;
    cout<<"plzz enter the size array\n";
    cin>>n;
    int a[n+1];// for new el so we creat creat one more block extra it contain garb
    for(i=0;i<n;i++){cin>>a[i];}
    cout<<"\narray elements : \n";
     for(i=0;i<n;i++){cout<<a[i]<<" ";}
     Insert(a,n+1,3,10);
     cout<<"\n now new array\n";
    for(i=0;i<n+1;i++){cout<<a[i]<<" ";}

   getch();
}
void Insert(int r[],int sz,int i,int x)
{
 int j;
// here we have to shift ele after inseerting arry to 1 pos ryt'
for(j=sz-1;j>i;j--)
{
    r[j]=r[j-1];
}
r[i]=x;
}
