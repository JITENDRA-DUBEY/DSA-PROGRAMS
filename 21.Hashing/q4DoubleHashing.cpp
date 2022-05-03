//jsg
#include<iostream>
#define size 10
using namespace std;
int Hash1(int key);
int Hash1(int key)
{
    return key%size;
}
int Hash2(int key)
{
    return (7-key%7);/// nearest prime number to 10;
}
int prob(int H[],int key)// this function return the next free space in array
{
   int i=0;
  //int index=Hash(key);
  while(H[(Hash1(key)+i*Hash2(key))%size]!=0)i++;
  return (Hash1(key)+i*Hash2(key))%size;
  
}
void insert(int H[],int key)
{
    int index=Hash1(key);
    if(H[index]!=0)// there is not empty space at that place;
    {
        index=prob(H,key);/// gave next free space in array;
    }
    H[index]=key;
}
int search(int H[],int key)
{
    int index=Hash1(key),i=0;
    while(H[(Hash1(key)+i*Hash2(key))%size]!=key)
       {
           if(H[(Hash1(key)+i*Hash2(key))%size]==0)// when we got free space;
           return -1;
           i++;
           }

    return (Hash1(key)+i*Hash2(key))%size;
}
int main()
{
    int H[10]={0};
    insert(H,5); insert(H,25); insert(H,15); insert(H,35); insert(H,95);//insert(H,45);
    for(int i=0;i<size;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<"\n serached el : "<<search(H,5);
    cout<<"\n serached el : "<<search(H,15); cout<<"\n serached el : "<<search(H,46);
    cout<<"\n serached el : "<<search(H,25);
    cout<<"\n serached el : "<<search(H,35);
    cout<<"\n serached el : "<<search(H,95);
   
    cout<<"\nSuccesfully terminated";
}