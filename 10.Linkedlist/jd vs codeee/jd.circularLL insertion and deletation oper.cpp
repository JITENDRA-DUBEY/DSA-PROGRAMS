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
/*void ReccDisplay(Node*p)
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
}/*/
void Insert(int pos,int x)
{
    Node*t=new Node,*p=head;
    t->data=x;
    if(pos==0)
    {
        if(head==NULL)// their is no node
        {
        t->next=t;//for circular
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
   int m,x,pos;
    int a[5]={10,20,30,40,50};
    //CreateAb(a,5);
    cout<<"\nEnter Total Number of Nodes :";
    cin>>m;

    while(m--)
    {
        cout<<"\nEnter Nodes Data and Position Number:\n";
        cin>>pos>>x;
        Insert(pos,x);
    }
     Display(head);
}

