//jsg for dele
#include<conio.h>
#include<iostream>
using namespace std;
void del(int *r,int sz,int i);
int main()
{
    int i,n;
    cout<<"plzz enter the size array\n";
    cin>>n;
    int a[n];// for new el so we creat creat one more block extra it contain garb
    for(i=0;i<n;i++){cin>>a[i];}
    del(a,n--,3);// bz after deleting size should be updaten--
    cout<<"now new array\n";
    for(i=0;i<n;i++){cout<<a[i]<<" ";}
}
void del(int r[],int sz,int i)
{
    // shift all the elme to 1 left pos after del index
    int j=i;
   for(j=i;j<sz-1;j++)
   {
       r[j]=r[j+1];
   }

}
