// jsg binary search this is only applicable for sorted array// print the index -1 repe not found;
#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
int Bs(int *r,int sz,int h,int l, int key);
int main()
{
    int i,n,l,h,key;
    cout<<"plzz enter the size array\n";
    cin>>n;
    int a[n];
    cout<<"plzz enter the array element in acending order\n";
    for(i=0;i<n;i++){cin>>a[i];}
    cout<<"plzz enter the key element\n";
    cin>>key;
    h=n-1;l=0;
    cout<<Bs(a,n,h,l,key);
}
int Bs(int *r,int sz,int h,int l, int key)
{
   if(l<=h)
   {   int mid=floor((l+h)/2);

       if(r[mid]==key)
       {
           cout<<"YES\n";
           return mid;
       }
       else if(r[mid]<key)
         return Bs(r,sz,h,mid+1,key);
       else
       return Bs(r,sz,mid-1,l,key);
   }
   else
   return -1;
}
