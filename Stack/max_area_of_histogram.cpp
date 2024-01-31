#include <iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> getNSL(int size,int *arr)
{
stack<pair<int,int>> s;
vector<int> left;
int psudo_index=-1;
for(int i=0;i<size;i++)
{
if(s.size( )==0){
left.push_back(psudo_index);
}
else if(s.top( ).first < arr[i]){
left.push_back(s.top( ).second);
}
else{
while(s.size( )>0 && s.top( ).first >= arr[i])s.pop( );
if(s.size( )==0)left.push_back(psudo_index);
else left.push_back(s.top( ).second);
}
s.push({ arr[i] , i });
}
return left;
}
vector<int> getNSR(int size,int *arr)
{
stack<pair<int,int>> s;
vector<int> right;
int psudo_index=7;
for(int i=size-1;i>=0;i--)
{
if(s.size( )==0)
{
right.push_back(psudo_index);
}
else if(s.top( ).first<arr[i])
{
right.push_back(s.top( ).second);
}
else
{
while(s.size( )>0 && s.top( ).first>=arr[i])s.pop( );
if(s.size( )==0)right.push_back(psudo_index);
else right.push_back(s.top( ).second);
}
s.push({arr[i],i});
}
reverse(right.begin( ),right.end( ));
return right;
}

int max_area_of_histogram(int size,int *arr)
{
vector<int> left=getNSL(size,arr);
vector<int> right=getNSR(size,arr);
int num=0;
int max=0;
for(int i=0;i<size;i++)
{
num=(right[i]-left[i]-1)*arr[i];
if(num>max)max=num;
}
return max;
}

int main(int argc,char* argv[ ])
{
int arr[argc-1];
vector<int> v;
for(int i=0;i<argc;i++)arr[i]=atoi(argv[i+1]);
int max=max_area_of_histogram(argc-1,&arr[0]);
cout<<"Maximium area of histogram is : "<<max<<endl;
return 0;
}