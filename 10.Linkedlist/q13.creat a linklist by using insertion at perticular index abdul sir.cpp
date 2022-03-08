//jsg create a link list by using insertion operation;
#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct Node
{
  int data;
  Node*next;
};
int Count=0;
Node *first=NULL;
void Insert(Node*p,int index,int x)
{
    //Count++;
   Node *t;
  if(index<0||index>Count++)
    {
      cout<<"\nsorry index number not available :";
      return;
    }// for first node;
    if(p==NULL)
    {
       t=new Node;
       t->data=x;
       t->next=NULL;
       first=t;
    }
    else
    {
         for(int i=0;i<index-1&&p;i++)
         {
           p=p->next;
         }if(p)
         {
          t=new Node;
          t->data=x;
          t->next=p->next;
          p->next=t;
         }

    }
}
void Display(Node*p)
{  cout<<"\nyour list data : ";
    while(p)
    {
      cout<<"\nelemnts : "<<p->data;
      p=p->next;
    }
}
int main()
{
   int n,i,x;
   while(1)
   {
      cout<<"\nDo you want insert  a node than press 1\n";
      cin>>n;
      if(n!=1)
        break;
      cout<<"\nPlease Enter the index num and value\n";
      cin>>i>>x;
      Insert(first,i,x);

   }
   Display(first);
}
