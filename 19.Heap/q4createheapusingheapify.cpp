// jsg Heap by using Heapify self madeIMP
#include<iostream>
using namespace std;
void  insertHaepify(int a[],int ,int );
void HeapbyHeapify(int a[],int n)// always insert ryt to left
{
    for(int i=n-1;i>=1;i--)
    {
        insertHaepify(a,i,8);
    }
}
void  insertHaepify(int a[],int n,int asz)
{
     int i=n,j=2*i;
     while(j<asz&&j+1<asz)
     {   //j=2*i;
         if(a[j+1]>a[j])
         j=j+1;
         if(a[i]<a[j])
         swap(a[i],a[j]);
         i=j;j=2*j;
     }
}
int main()
{
    int a[8]={0,5,10,30,20,35,40,15};
    //int a[13]={0,5,10,30,20,35,40,15,25,60,75,80};
    HeapbyHeapify(a,8);
    for(int i=1;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
}
