//jsg circular link list;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node*next;
};
Node*head=NULL;
Node*last=NULL;
int Count=0;
/*void Create(int a[],int n)
{
    Node*t=new Node;
    t->data=a[0];
    t->next=NULL;
    last=t;
    head=t;
    for(int i=1;i<n;i++)
    {
       Node*t=new Node;
       t->data=a[i];
       t->next=NULL;
       last->next=t;
       last=t;
    }// for circular ll ass head in last node next;
    last->next=head;
}*/

void CreateAb(int a[],int n)
{
    Node*t;
    head=new Node;
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
       Node*t=new Node;
       t->data=a[i];
       t->next=last->next;//assgn head in each node
       last->next=t;
       last=t;
    }
    Count=n;
}
void Display(Node*p)
{
    cout<<"\nYour List : ";
    if(head!=NULL)
   {
     do
    {
        cout<<"\nElement : "<<p->data;
        p=p->next;
    }while(p!=head);
   }
   else
    cout<<"\nList is empty";
}
void ReccDisplay(Node*p)
{
    if(p!=NULL){
    static int flag=0;
    if(p!=head||flag==0)
    {
         cout<<"\nElement Recc: "<<p->data;
         flag=1;
         ReccDisplay(p->next);
    }
    // at last make flag==0
    flag=0;
    }
    else
       cout<<"\nList is empty";
}

int RJDDisplay(Node*p)
{  if(p!=NULL)
    {
   cout<<"\nElement RcJd: "<<p->data;
   if(p->next==head)
      return-1;
   RJDDisplay(p->next);
    }
    else
        cout<<"\nList is empty";
}
void Insert(int pos,int x)
{
    Node*t=new Node,*p=head;
    t->data=x;
    if(pos==0)
    {
        if(head==NULL)// their is no node
        {
        t->next=t;
        head=t;
        Count++;
        }
        //if i have only one node
        if(head->next==head)
        {
            t->next=head;
            head->next=t;
            head=t;
            Count++;
        }
        else
        {  //cout<<"\njsaj";
            while(p->next!=head){p=p->next;}
            p->next=t;
            t->next=head;
            head=t;
            Count++;
        }
    }
    else if(1<=pos&&pos<=Count)
    {    p=head;//vvmi
         for(int i=1;i<pos;i++){p=p->next;}
         t->next=p->next;
         p->next=t;
         Count++;
    }
    else
    cout<<"\n\nInvalid Position we can't Insert";

}
int main()
{

    int a[5]={10,20,30,40,50};
    //CreateAb(a,5);
    Display(head);
    cout<<"\nYour List Recc: ";
    ReccDisplay(head);
    cout<<"\nYour List By Jd : ";
    RJDDisplay(head);
     Insert(2,11);
     Display(head);
      Insert(0,13);
     Display(head);
     Insert(1,14);
     Display(head);
     Insert(10,14);
     Display(head);
     Insert(0,17);
     Display(head);
      //Insert(1,114);
     //Display(head);



}

