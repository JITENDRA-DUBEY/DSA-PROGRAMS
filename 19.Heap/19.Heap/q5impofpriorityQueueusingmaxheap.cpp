// jsg priority Queue using maxHeap
// priority Queue means always delete element of heghest priority i.e root element of max heap
#include<iostream>
using namespace std;
void insert(int a[],int n);
void Create(int a[],int n){
   for(int i=2;i<n;i++)
   {
    insert(a,i);
   }
}
void insert(int a[],int n)
{
    int i=n;
    int temp=a[i];
    while(i>1&&temp>a[i/2])
    {
          a[i]=a[i/2];i=i/2;
    }
    a[i]=temp;
}
int deletehigher(int a[],int n)// 
{
   int i=n,x=a[1],y=a[n],j;
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
           i=j;j=2*i;
           
       }else{
               break;
           }
    
   }return x;
}
int main()
{
 // int a[8]={0,50,10,30,20,40,60,70};
 int a[8]={0,10,20,30,25,5,40,35};
  int pQ[8],k=0;
  Create(a,8);
  for(int i=7;i>=1;i--)
  {
    pQ[k++]=deletehigher(a,i);
  }
  for(int i=1;i<8;i++)
  {
      cout<<a[i]<<" ";
  }
  cout<<"priority Queue Deleted element : \n";
 for(int i=0;i<8;i++)
  {
      cout<<pQ[i]<<" ";
  }

}