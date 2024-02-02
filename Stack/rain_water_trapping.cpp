#include <iostream>
#include<vector>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

int get_rain_water_area(int size,int *arr)
{
int maxL[size];
int maxR[size];
int max=arr[0];
maxL[0]=max;
for(int i=1;i<size;i++)
{
if(arr[i]>max)max=arr[i];
maxL[i]=max;
}
max=arr[size-1];
maxR[size-1]=max;
for(int i=size-2;i>=0;i--)
{
if(arr[i]>max)max=arr[i];
maxR[i]=max;
}
int min;
int area=0;
for(int i=0;i<size;i++)
{
if(maxL[i]<maxR[i])min=maxL[i];
else min=maxR[i];
area=area+(min-arr[i])*1;
}
return area;
}

int main(int argc,char* argv[ ])
{
int arr[argc-1];
int area;
for(int i=0;i<argc;i++)arr[i]=atoi(argv[i+1]);
area=get_rain_water_area(argc-1,&arr[0]);
cout<<"Area of water is : "<<area<<endl;
return 0;
}