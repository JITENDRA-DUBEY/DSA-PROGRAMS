#include<iostream>
using namespace std;
int i=0;
int sum(int *a,int n)
{
    if(n==0)
    return 0;
    else
    return a[n-1]+sum(a,n-1);
}
bool issort(int a[],int n)
{
    if(n==0||n==1)
    return true;// because single or 0  element is always sorted
    else{
         if(a[0]>a[1])
         {
            return false;
         }
         else
         return issort(a+1,n-1);// pointer to next ;oation
    }
}
bool binarysearch(int a[],int s,int e,int key)
{
    if(s>e)
    return false;
    int mid=s+(e-s)/2;
    if(a[mid]==key)
    return true;
    else if(key>a[mid])// search on right half
    {
        return binarysearch(a,mid+1,e,key);
    }
    else
    {
         return binarysearch(a,s,mid-1,key);
    }

}
bool findel(int *a,int n,int key)
{
    if(n==0)
    return false;// u traverse thorugh whole list and still u dont found that element.
    if(a[0]==key)
    return true;
    else
     return findel(a+1,n-1,key);

}
int main()
{
    int a[]={2,4,18,18,19};
   if(issort(a,5))
   cout<<"yes sorted"<<endl;
   else
   cout<<"Not sorted";
   cout<<"sum is : "<<sum(a,5)<<endl;
   if(findel(a,5,18))
   cout<<"element is found "<<endl;
   else
   cout<<"No found "<<endl;
   if(binarysearch(a,0,5,18))
   cout<<"element is found "<<endl;
   else
   cout<<"No found "<<endl;
}
/*int i=0;
bool issort(int a[],int n)
{
    if(n==0||n==1)// there is only single el
    return true;
    if(i==n)
    return true;// when u reach till last el
    else{
        if(a[i+1]<a[i])
       {  return false;}
        i++;
        issort(a,n);
        }
}*/