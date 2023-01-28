#include<iostream>
using namespace std;

int main()
{
	int i,j,n,w;
	cout<<"Enter the number of coin : ";
	cin>>n;
	int a[n];
	cout<<"Enter the denomination of coin : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter the total coin sum : ";
	cin>>w;
	int c[n][w+1];
	for(i=0;i<n;i++)
		c[i][0]=0;
	for(j=1;j<=w;j++)
	{
		if(j%a[0]==0)
			c[0][j]=j/a[0];
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
				c[i][j]=min(c[i-1][j],1+c[i][j-a[i]]);
		}
	}
	
   cout<<"Minimum number of coins : "<<c[n-1][w]<<endl;
   cout<<endl<<"The chossen coin are : ";
   j=w;
   for(i=n-1;i>=1;i--)
   {
   	while(c[i][j]!=c[i-1][j])
   	{
   		cout<<a[i]<<" ";
   		j -=a[i];
   	}
   }
   cout<<endl;
   return 0;
}