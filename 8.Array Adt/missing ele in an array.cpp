//found duplicate  element by using hash table
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,mx;
    cout<<"\nplzz enter the size of the array";
    cin>>n;
    int a[n],i;
    for(i=0;i<n;i++){cin>>a[i];}
    mx=*(max_element(a,a+n));
    //cout<<mx;
     int hash[mx+1]={0};
    // those element present in a arry that update by 1 in hash array;
    for(i=0;i<n;i++)
    {
        hash[a[i]]++;
    }// for printing
    for(i=0;i<mx+1;i++)
    {
        if(hash[i]>1)
            cout<<i<<" occur :"<<hash[i]<<"times\n";
    }


}
