// jsg linear probing than close chaining here we can store n/2 max element
#include<iostream>
using namespace std;
int G[10]={0};
void insert(int key)
{
    int k=key%10,i=0;
    if(G[(k+i)%10]==0)
    {
      G[k]=key;
    }
    else{// find out next free space  by using probing 
   while(G[(k+i)%10]!=0)
          i++;
     G[(k+i)%10]=key;
    }

}
int  search(int key)// find out key linearly if u got freespace than stop and says that there is no free space
{
    if(G[key%10]==key)
    return key%10;
    int i=1;
    while(G[((key%10)+i)%10]!=key)
    {
        if (G[((key%10)+i)%10]==0)// there is free space so element nit found
       { return -1;}
        i++;
    }
    return (((key%10)+i)%10) ;

}
void display()
{
    for(int i=0;i<10;i++)
    {
        cout<< G[i]<<" ";
    }
}
int main()
{
    int a[9]={26,30,45,23,25,43,74,19,29};
    for(int i=0;i<9;i++)
    {
        insert(a[i]);
    }
    cout<<"Liear Probing : "<<endl;
    display();
    
    cout<<"\nindex value "<<search(40);
     cout<<"\nindex value "<<search(74);
      cout<<"\nindex value "<<search(45); cout<<"\nindex value "<<search(22);
    cout<<"\nSuccesful ";
}