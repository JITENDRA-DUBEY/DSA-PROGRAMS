// updated version of leaear search
#include<conio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int ln(int r[],int sz,int key);
int main()
{
    int i,n,key;
    cout<<"plzz enter the size array\n";
    cin>>n;
    int a[n];
    cout<<"plzz enter the array element in acending order\n";
    for(i=0;i<n;i++){cin>>a[i];}
    cout<<"plzz enter the key element\n";
    cin>>key;
    cout<<ln(a,n,key);
}
int ln(int r[],int sz,int key)
{
    int i;
    for(i=0;i<sz;i++)
    {
        if(r[i]==key)
        {
            swap(r[i],r[i-1])
            cout<<r[i-1]<<"\n";
             return i-1;
        }
    }
    return -1;
}
