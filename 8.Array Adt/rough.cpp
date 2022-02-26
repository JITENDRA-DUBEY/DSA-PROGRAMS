#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[5]={10,2,3,15,6};
    cout<<*(max_element(a,a+5));
}
