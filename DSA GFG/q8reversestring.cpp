// jsg 
#include<iostream>
#include<string.h>
using namespace std;
string reversestr(string str,int i,int j)
{
     if(i<=j)
     
        { swap(str[i],str[j]);
         return  reversestr(str,++i,--j);}
         return str;
     
}
void reversestring (string& str,int i,int j)
{
     if(i>j)
     return;
         swap(str[i],str[j]);
           reversestring(str,++i,--j);
         
     
}
/*void rrecverse(string& str,int n)
{
    if(n>=1)
    {
        swap(str[0],str[n]);
        rrecverse(str[1],n-1);
    }
}*/
int n=6;
void arrayrev(int a[],int i)
{ 
    if(i>=n/2)
      return;
    swap(a[i],a[n-1-i]);i++;
    arrayrev(a,i);
}
int sz;
bool checkispaildram(string s,int i)
{
   
    if(i>=sz/2)
    return true;
     if(s[i]!=s[sz-1-i])
        return false;
    else{
       
        i++;
       return checkispaildram(s,i);
    }
}
int main()
{
   /*string str="jitendra kumar";
    reversestring(str,0,str.length()-1);
    cout<<str;
    int arr[]={1,2,3,4,5,6};
    arrayrev(arr,0);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\nsuccessfully terminated"<<endl;*/
   string pail="abbckscbba";
   sz=pail.length();
   if(checkispaildram(pail,0))
      cout<<"It is pail "<<endl;
      else
      cout<<"It is not pail "<<endl;

}