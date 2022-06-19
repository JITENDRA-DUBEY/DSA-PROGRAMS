// jsg
#include<iostream>
#include<string.h>
using namespace std;
void permstr(char str[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {   k=1;
       char curr[n];
       curr[0]=str[0];// than element is fix
       
        for(j=1;j<n;j++)
        {
                if(i!=j)
                curr[k++]=str[j];
            
        }
        curr[k++]=str[i];
       curr[k]='\0';
       cout<<"\nperm "<<endl;
       for(int m=0;m<n;m++)
       cout<<curr[m];
    }
}
int main()
{
    char str[]={'a','b','c','d','\0'};
    for(int i=0;i<4;i++)
    {
      swap(str[0],str[i]);
      cout<<i<<"th index "<<endl;
       permstr(str,4);
    }
   
    cout<<"\nsuccessful ";
}