#include<iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

stack<int> stk1,stk2;
void push( )
{
int num;
cout<<"Enter number to push on stack : ";
cin>>num;
if(stk1.size()==0)stk2.push(num);
else if(stk2.top( )>num)stk2.push(num);
stk1.push(num);
cout<<num<<" pushed"<<endl;
}
void pop( )
{
if(stk1.top()==stk2.top())stk2.pop( );
stk1.pop( );
}
void top( )
{
cout<<"Top is : "<<stk1.top( )<<endl;
}
void minElem( )
{
cout<<"Minimum element is : "<<stk2.top( )<<endl;
}
int main( )
{
int choice;
while(1)
{
cout<<"(1)->Push on Stack: "<<endl;
cout<<"(2)->Pop from Stack: "<<endl;
cout<<"(3)->Stack top: "<<endl;
cout<<"(4)->Min element from Stack: "<<endl;
cout<<"(5)->Exit : "<<endl;
cout<<"Enter your choice : ";
cin>>choice;
if(choice==1)push( );
else if(choice==2)pop( );
else if(choice==3)top( );
else if(choice==4)minElem( );
else if(choice==5)break;
else cout<<"Invalid choice"<<endl;
}
return 0;
}