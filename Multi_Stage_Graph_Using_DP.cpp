#include<iostream>
using namespace std;

int main()
{
	int i,n=8,stage=4,min,k;
	int d[n+1],path[n+1],cost[n+1];
	int c[n+1][n+1]={
		{0,0,0,0,0,0,0,0,0},
		{0,0,2,1,3,0,0,0,0},
		{0,0,0,0,0,2,3,0,0},
		{0,0,0,0,0,6,7,0,0},
		{0,0,0,0,0,6,8,9,0},
		{0,0,0,0,0,0,0,0,6},
		{0,0,0,0,0,0,0,0,4},
		{0,0,0,0,0,0,0,0,5},
		{0,0,0,0,0,0,0,0,0}
	};
    cost[n]=0;
    for(i=n-1;i>=1;i--)
    {
    	min=32767;
    	for(k=i+1;k<=n;k++)
    	{
    		if(c[i][k]!=0 && c[i][k]+cost[k]<min)
    		{
    			min=c[i][k]+cost[k];
    			d[i]=k;
    		}
    	}
    	cost[i]=min;
    }
    cout<<"Minimum number of cost : "<<cost[1]<<endl;
    path[1]=1;path[stage]=n;
    for(i=2;i<stage;i++)
    	path[i]=d[path[i-1]];
    cout<<"Selected path for Minimum cost : ";
    for(i=1;i<=stage;i++)
    	cout<<path[i]<<" ";
    cout<<endl;
    return 0;
}