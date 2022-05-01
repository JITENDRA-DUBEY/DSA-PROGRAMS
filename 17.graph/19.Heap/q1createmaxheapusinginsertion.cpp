// jsg Heap sort.insertion+deletion
#include<iostream>
using namespace std;
void insert(int a[],int n);
void createmaxHeap(int a[],int n)
{
  for(int i=2;i<n;i++)// here we take first element as its original pos than from 2 pos start insertion in max heap;
  {
      insert(a,i);
  }
 
}
void insert(int a[],int n)
{
    int temp=a[n],i=n;
    while(temp>a[i/2]&&i>1)
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
int Deleteheap(int a[],int n)///deleting one el that is root from heap
{
    int x=a[1],i,j;
    int y=a[n];
    a[1]=a[n];
    a[n]=x;
    i=1;j=2*i;
    while(j<n-1)
    {
        if(a[j+1]>a[j])
             j=j+1;
        if(a[i]<a[j])
        {
            swap(a[i],a[j]);
            i=j;j=2*j;
        }
        else
         break;
    }
    //a[n-1]=x;
    return x;
   
}
int main()
{
int a[8]={0,10,20,30,25,5,40,35};// here we start elemnet of heap from 1 index
createmaxHeap(a,8);cout<<"MaxHeap : "<<endl;
cout<<"\nDeleted Element = "<<Deleteheap(a,7)<<endl;
cout<<"\nDeleted Element = "<<Deleteheap(a,6)<<endl;
cout<<"\nDeleted Element = "<<Deleteheap(a,5)<<endl;
cout<<"\nDeleted Element = "<<Deleteheap(a,4)<<endl;
cout<<"\nDeleted Element = "<<Deleteheap(a,3)<<endl;
cout<<"\nDeleted Element = "<<Deleteheap(a,2)<<endl;  
cout<<"Sorted Arrary is "<<endl;
for(int i=1;i<8;i++)
{
   cout<<a[i]<<" ";
}

}