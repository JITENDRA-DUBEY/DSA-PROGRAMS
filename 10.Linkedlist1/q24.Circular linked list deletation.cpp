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
int Delete(int pos)
{     Node*p,*temp;int x=-1,i;
    if(pos<=0||pos>Count)
        return -1;
        if(pos==1)
        {
        while(p->next!=head){p=p->next;}
        x=head->data;
        if(p==head)// that means there is only single node;
        {
            delete head;
            head=NULL;
            Count--;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
            Count--;
        }

       }
    else
    {   p=head;//vvmi
        for(i=1;i<pos-1;i++)
            p=p->next;
        temp=p->next;
        p->next=temp->next;
        x=temp->data;
        delete temp;

        Count--;
    }

return x;

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
     cout<<"\nDeleted ele : "<<Delete(1);
      Display(head);
       cout<<"\nDeleted ele : "<<Delete(0);
      Display(head);
            cout<<"\nDeleted ele : "<< Delete(3);
      Display(head);
            cout<<"\nDeleted ele : "<< Delete(5);
      Display(head);
}

