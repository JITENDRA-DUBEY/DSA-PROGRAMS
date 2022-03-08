// JSG Creat a linked list// and insert a node in shortest postion ;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
Node*first=NULL;
Node*last=NULL;
void InsertLast(int x)
{
    Node*t=new Node;
       t->data=x;
       t->next=NULL;

   if(first==NULL)// that means there is no node avialable
   {
       first=t;
       last=t;
   }
   else
   {
   last->next=t;
   last=t;
   }
}
void Display(Node*p)
{
    cout<<"\nYour List : ";
    while(p)
    {
        cout<<"\nElement : "<<p->data;
        p=p->next;
    }
}
void InsertShortNode(Node *p,int x)
{
    Node*q=NULL,*t=new Node;
    t->data=x;
    t->next=NULL;
    //if key ele is smaller than smallest elem than we insert a new node at the left of first node;
    if(first==NULL)// that means there is no node 
    {
    	first =t;
	}
	else{	
        while(p&&p->data<x) // whenever we found a greater ele than key elem move p and q;
        {
           q=p;p=p->next;
        }
        if(p==first)
        {
        	t->next=first;
        	first=t;
		}// insert a new node between q and p 
		else{
		
        t->next=q->next;
        q->next=t;
       }
     } 
}

int main()
{   int n;
    while(1)
    {   int x,n;
        cout<<"\nDo you want to insert a node press 1\n";
        cin>>n;
        if(n!=1){break;}
        cout<<"\nEnter the data :";
        cin>>x;
        InsertLast(x);
    }
    Display(first);
    InsertShortNode(first,5);
    Display(first);
    InsertShortNode(first,1);
    Display(first);
    InsertShortNode(first,15);
    Display(first);
    return 0;
}
