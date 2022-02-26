// jsg
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int ln(int a[],int n,int key);
int main()
{
    int n,i,key;
    cout<<"\nplzz enter the size of array";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"plzz enter the key el";
    cin>>key;
    // for linear search
    cout<<"\nindex : "<<ln(a,n,key);
      for(i=0;i<n;i++)
    {
        cout<<"\n"<<a[i];
    }


}
int ln(int a[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            swap(a[i],a[0]);
            return 0;
        }
    }
    return -1;
}
