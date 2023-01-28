#include<iostream>
using namespace std;

int main()
{
	int i,j,n,w;
	cout<<"Enter the number of coins : ";
	cin>>n;
	int a[n];
	cout<<"Enter the denomination of coins : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the value of coins sum : ";
	cin>>w;
	int c[n][w+1];
	for(i=0;i<n;i++)
		c[i][0]=1;
	for(j=1;j<=w;j++)
	{
		if(j%a[0]==0)
			c[0][j]=1;
		else
			c[0][j]=0;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(a[i]>j)
				c[i][j]=c[i-1][j];
			else
				c[i][j]=c[i-1][j]+c[i][j-a[i]];
		}
	}
	cout<<"Minimum number of Ways to get total sum : "<<c[n-1][w]<<endl;
	return 0;
}