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
int psudo_index=size;
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

int max_area_rect_in_binary_matrix(int n,int m,int **arr)
{
int v[m];
for(int i=0;i<m;i++)v[i]=(arr[0][i]);
int max=max_area_of_histogram(m,&v[0]);
int num;
for(int i=1;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(arr[i][j]==0)v[j]=0;
else v[j]=v[j]+1;
}
num=max_area_of_histogram(m,&v[0]);
if(num>max)max=num;
}
return max;
}

int main( )
{
int row;
int column;
cout<<"Enter number of rows : ";
cin>>row;
cout<<"Enter number of columns : ";
cin>>column;
int **arr=new int*[row];
for(int i=0;i<row;i++)
{
arr[i]=new int[column];
for(int j=0;j<column;j++)
{
cin>>arr[i][j];
}
}
int max=max_area_rect_in_binary_matrix(row,column,arr);
cout<<"Maximium area of rectangle in a binary matrix is  : "<<max<<endl;
return 0;
}