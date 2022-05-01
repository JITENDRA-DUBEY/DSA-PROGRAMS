#include<iostream>
using namespace std;
void insert(int a[],int n);
void createminHeap(int a[],int n)
{
     for(int i=2;i<n;i++)
     {
         insert(a,i);
     }
}
void insert(int a[],int n)
{
    int temp=a[n],i=n;
    while(i>1&&temp<a[i/2])// fro min heap if element is greater than move it at ith loc 
    {
         a[i]=a[i/2];
         i=i/2;
    }
    a[i]=temp;

}
int main()
{
int a[8]={0,10,45,30,25,20,40,35};// here we start elemnet of heap from 1 index
createminHeap(a,8);
cout<<"MinHeap : "<<endl;
for(int i=0;i<8;i++)
{
   cout<<a[i]<<" ";
}
}