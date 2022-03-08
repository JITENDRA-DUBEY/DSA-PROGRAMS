#include<iostream>
#include<math.h>
using namespace std;
class Polynomial{
struct node{
    int coef;
    int expo;
    node *next;
};
node *head;
node *last;
public:
Polynomial(){
    head=NULL;
    last=NULL;
}
void Insert(int,int);
int calculate(int);

};
int Polynomial::calculate(int x){
node *p;
int sum=0;
p=head;
while(p){
    sum+=p->coef*(pow(x,p->expo));
    p=p->next;
}
return sum;
}
void Polynomial::Insert(int x,int y){
node *t;
t=new node;
t->coef=x;
t->expo=y;
t->next=NULL;
if(head==NULL){
    head=last=t;
}
else{
    last->next=t;
    last=t;
}
}

int main(){
 Polynomial p;
 int no,power,x;

 for(int i=0;i<3;i++){
 cout<<"Enter the no. and power  ";
 cin>>no>>power;
   p.Insert(no,power);
   cout<<endl;
 }
 cout<<"Enter the value of x for calculating polynomial ";
 cin>>x;
 cout<<"The value of the polynomial is "<<p.calculate(x)<<endl;
}