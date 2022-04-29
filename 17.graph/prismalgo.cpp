// jsg prism algorithm for minium cost spanning tree
#include<iostream>
using namespace std;
#define I 35267
int cost[][8]
{
{I,I,I,I,I,I,I,I},
{ I,I,25,I,I,I,15,I},
{I,25,I,12,I,I,I,10},
{I,I,12,I,8,I,I,I},
{I,I,I,8,I,16,I,14},
{I,I,I,I,16,I,20,18},
{I,5,I,I,I,20,I,I},
{I,I,10,I,14,18,I,I}};
int near[8]={I,I,I,I,I,I,I,I};
int t[2][6];
void prism()
{
    int i,j,u,v,k,n=7,min=I;
    // first find out the minimum cos edge from upper triangular matrix;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    t[0][0]=u;t[1][0]=v;
    near[u]=near[v]=0;
    /* 
    1. find out the minimum cost edge from near array and than put that e*/
    for(i=1;i<=n;i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][u]<cost[i][v])//mi
            {
                near[i]=u;
            }
            else
            near[i]=v;
        }
    }
    // here we are going to perform repeating steps
    for(i=1;i<n-1;i++)// because one edge we already slected and there are total n-1 edge for spanning tree
    {
         min=I;
         for(j=1;j<=n;j++)
         {
             if(near[j]!=0&&cost[j][near[j]]<min)// for finding minimum cost edge from near array
             {
                  k=j;
                 min =cost[j][near[j]];
                
             }
         }
              t[0][i]=k;t[1][i]=near[k];// here i did mistake
             near[k]=0;

    
        
         for(j=1;j<=n;j++)
         {
             if(near[j]!=0&&cost[j][k]<cost[j][near[j]])
             {
                 near[j]=k;
             }
         }
    }
      for(int i=0;i<n-1;i++)
    {
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
    }

}
int main()
{
    prism();
  

}
  