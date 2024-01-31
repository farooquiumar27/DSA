#include <iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> nearest_greater_to_left(int size,int *arr)
{
stack<int> s;
vector<int> v;
for(int i=0;i<size;i++)
{
if(s.size( )==0){
v.push_back(-1);
}
else if(s.top( )>arr[i]){
v.push_back(s.top( ));
}
else{
while(s.size( )>0 && s.top( )<=arr[i])s.pop( );
if(s.size( )==0){
v.push_back(-1);
}
else{
v.push_back(s.top( ));
}
}
s.push(arr[i]);
}
return v;
}

int main(int argc,char* argv[ ])
{
int arr[argc-1];
vector<int> v;
for(int i=0;i<argc;i++)arr[i]=atoi(argv[i+1]);
v=nearest_greater_to_left(argc-1,&arr[0]);
for(int i=0;i<v.size( );i++)cout<<v[i]<<endl;
return 0;
}