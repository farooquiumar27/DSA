//In this we will take the case of consecutive_smaller_or_equal_before_it

#include <iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> consecutive_smaller_or_equal_before_it(int size,int *arr)
{
stack<pair<int,int>> s;
vector<int> v;
for(int i=0;i<size;i++)
{
if(s.size( )==0){
v.push_back(-1);
}
else if(s.top( ).first > arr[i]){
v.push_back(s.top( ).second);
}
else{
while(s.size( )>0 && s.top( ).first <= arr[i])s.pop( );
if(s.size( )==0)v.push_back(-1);
else v.push_back(s.top( ).second);
}
s.push({ arr[i] , i });
}
for(int i=0;i<size;i++)v[i]=i-v[i];
return v;
}

int main(int argc,char* argv[ ])
{
int arr[argc-1];
vector<int> v;
for(int i=0;i<argc;i++)arr[i]=atoi(argv[i+1]);
v=consecutive_smaller_or_equal_before_it(argc-1,&arr[0]);
for(int i=0;i<v.size( );i++)cout<<v[i]<<endl;
return 0;
}