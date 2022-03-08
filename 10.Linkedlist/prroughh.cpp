#include<stdio.h>
#include<stdlib.h>
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
void Rdisplay(struct Node * head)
{
   struct Node *temp=head;
    while(temp!=NULL|| temp->next!=NULL)
    {    printf("%d",temp->data);
         Rdisplay(temp->next);

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

}
