//jsg Concination of two ll;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  Node *next;
};
//int Count=0;
Node*first=NULL;
Node*last=NULL;
Node*second=NULL;// thisd is a pointer points to second ll;
void InsertLast(int x)
{
    Node*t=new Node;
       t->data=x;
       t->next=NULL;
   if(first==NULL||second==NULL)// that means there is no node avialable
   {
       if(first==NULL&&last==NULL)
       {first=t;
       last=t;}
       else
       {
           if(second==NULL&&last==NULL)
           {
               second=t;
               last=t;
           }
       }
   }
   if(first!=NULL||second!=NULL)
   {
   last->next=t;
   last=t;
   }
}

// for concenataion
void Concenate(Node*p)
{
    while(p->next)
    {
        p=p->next;
    }
    p->next=second;
    second=NULL;
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
void Rmdupshort(Node *p)
{
    Node*q;
    p=first;
    q=first->next;
    while(q)// q!=NULL
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
            {
                p->next=q->next;
                delete q;
                q=p->next;

            }
    }
}
// print duplicate element in a shorted array
void PrintDupele(Node*p)
{
    Node*q=p;
    p=p->next;
    int x=-62556;
    int dup=1;
    while(p)
    {

        if(q->data==p->data)
        {
            dup++;
            if(x!=p->data)
            {
                cout<<"\nDuplicate Element : "<<p->data<<" ocuur at "<<dup<<" times !";
                x=q->data;
                dup==1;
            }
        }
        q=p;
        p=p->next;
    }
}
int main()
{   int n1,n2,x;
    while(1)
    {
        cout<<"\nDo you want to insert a node in first ll than press any key and for stopping press 1\n";
        cin>>n1;
        if(n1==1){break;}
        cout<<"\nEnter the data :";
        cin>>x;
        InsertLast(x);
    }
    cout<<"\nFirst ll :-";
    Display(first);
    // again becam,e last to null;
    last=NULL;
     while(1)
    {   //int x,n;
        cout<<"\nDo you want to insert a node in sec ll press any for stoping press 1\n";
        cin>>n2;
        if(n2==1){break;}
        cout<<"\nEnter the data :";
        cin>>x;
        InsertLast(x);
    }
     cout<<"\nSecond ll :-";
      Display(second);
    // cout<<"\n duplicate ele\n";
    //PrintDupele(first);
    //Rmdupshort(first);
    cout<<"\nNow Concinate ll :";
     Concenate(first);
    Display(first);
    return 0;
}
