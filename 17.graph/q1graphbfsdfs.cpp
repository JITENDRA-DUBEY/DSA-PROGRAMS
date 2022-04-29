// jsg graph bst and dst
#include<iostream>
using namespace std;
class Node{
         public:
         int data;
         Node*next;
         Node(){next=NULL;}
};
class Queue
{
    public :
     Node*front,*rear;
     Queue()
     {
         front=rear=NULL;
     }
     void enQueue(int data);
     int deQueue();
     int isEmpty();
     void display();
};
void Queue::enQueue(int data)
{
   Node*t=new Node();
   t->data=data;
   if(front==NULL)
   {
       front=rear=t;
   }
   else{
       rear->next=t;
       rear=t;
   }
}
int Queue::deQueue()
{
    if(front==NULL)
        return -1;
     // deletation always done form top 
     Node*temp=front;
         front=front->next;
         int x=temp->data;
         delete temp;
         return x;
}
int Queue::isEmpty()
{
    if(front==NULL)
    return 1;
    else
    return 0;
}
void Queue::display()
{
    Node*p=front;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
void BFS(int G[][7],int start ,int n)// here start is starting vertex n total numbwer of vertex
// it is just like level order of binary tree;
{
  int visited[7]={0};
  Queue q;
  int i,j;
  i=start;
  cout<<i<<" ";
  visited[i]=1;
  q.enQueue(i);
  while(!q.isEmpty())
  {
      i=q.deQueue();
  for(j=1;j<n;j++)//for exploring all adjacent node of 
  {
    if(G[i][j]==1&&visited[j]==0)// that there is an edge between i and j and also j is not visited;
    {
         visited[j]=1;
         cout<<j<<" ";
         q.enQueue(j);
    }
  }
  }
}
void DFS(int G[][7],int start,int n)
{
    int i=start;
    static int visited[7]={0};
    if(visited[i]==0)
    {
        cout<<i <<" ";
        visited[i]=1;
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1&&visited[j]==0)// not visited
            {
              DFS(G,j,n);
            }
        }
    }
    
}
int main()
{
    int G[7][7]={
        {0,0,0,0,0,0,0},{0,0,1,1,0,0,0},{0,1,0,0,1,0,0},{0,1,0,0,1,0,0},

            {0,0,1,1,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0}};
            cout<<"\nBFS search : \n";
            BFS(G,3,7);
             cout<<"\nDFS search : \n";
            DFS(G,4,7);
    
   
}