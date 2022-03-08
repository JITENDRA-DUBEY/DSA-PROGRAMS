#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node * next;
};
struct Node*head=NULL;

void push(int data)
{
    struct Node *temp =(struct Node *)malloc(sizeof(struct Node));
    temp->data= data;
    temp->next =head;
    head=temp;
}
void Rdisplay(struct Node * p)
{
    //struct Node *temp=head;
    if(p)
    {
         printf("%d\t",p->data);// this line comes before calling function ;
         Rdisplay(p->next);

         }

}
void Rrrdisplay(struct Node * p)
{
    if(p==NULL)
    {
       cout<<"\nJd";
        return;
    }

    if(p)
    {
      Rrrdisplay(p->next);
      cout<<"\nele "<<p->data;
    }

}
int main()
{
    int n,i,x;
    printf("How many numbers=");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x);
    }
    Rdisplay(head);
    Rrrdisplay(head);

}
