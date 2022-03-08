// jsg stack impletation by using array;
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Stack
{
    int Size;
    int Top;
    int *S;
};
void Create(Stack*st)
{
    cout<<"\nEnter the size of stack";
    cin>>st->Size;
    st->Top=-1;
    st->S=new int[st->Size-1];
}
void Push(Stack*st,int x)
{
    if(st->Top==st->Size-1)
    cout<<"\nOverFlow";//stack is already full;
    else
    {
        st->S[++(st->Top)]=x;
    }
}
int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,4);
    Push(&st,8);

}