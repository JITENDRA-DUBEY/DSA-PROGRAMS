#include<iostream>
using namespace std;
int minindex=-1;
int minn=INT32_MAX;
void recminind(int a[],int s,int e)
{
    if(s>e)
    return ;
    else{
        if(a[s]<minn)
        {
            minn=a[s];
            minindex=s;
        }
         if(a[e]<minn)
        {
            minn=a[e];
            minindex=e;
        }
    }
    recminind(a,s+1,e-1);
}
int main()
{
    int a[]={5,-4,1,-21,-13};
    recminind(a,0,4);
    cout<< minindex;
}