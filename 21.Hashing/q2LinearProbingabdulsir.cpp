//jsg
#include<iostream>
#define size 10
using namespace std;
int Hash(int key);
int Hash(int key)
{
    return key%size;
}
int prob(int H[],int key)// this function return the next free space in array
{
   int i=0;
  int index=Hash(key);
  while(H[(index+i)%size]!=0)i++;
  return (index+i)%size;
  
}
void insert(int H[],int key)
{
    int index=Hash(key);
    if(H[index]!=0)// there is not empty space at that place;
    {
        index=prob(H,key);/// gave next free space in array;
    }
    H[index]=key;
}
int search(int H[],int key)
{
    int index=Hash(key),i=0;
    while(H[(index+i)%size]!=key)
       {
           if(H[(index+i)%size]==0)// when we got free space;
           return -1;
           i++;
           }

    return (index+i)%size;
}
int main()
{
    int H[10]={0};
    insert(H,12); insert(H,25); insert(H,35); insert(H,36);
    for(int i=0;i<size;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<"\n serached el : "<<search(H,36);
    cout<<"\n serached el : "<<search(H,12); cout<<"\n serached el : "<<search(H,46);
    cout<<"\n serached el : "<<search(H,25);
    cout<<"\n serached el : "<<search(H,35);
   
    cout<<"\nSuccesfully terminated";
}