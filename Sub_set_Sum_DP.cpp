#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main()
{
	set<int> s;
	set<int>::iterator it;
	int w,n,i,j,x;
	cout<<"enter the number of elements : ";
	cin>>n;
	int a[n];
	cout<<endl<<"enter the elements of set : ";
	for(i=0;i<n;i++)
	{
		cin>>x; 
		a[i]=x;
		s.insert(x); 
	}
	cout<<endl<<"enter the value total sum : ";
	cin>>w;
	int set[n+1][w+1];
	for(i=0;i<=n;i++)
		set[i][0]=1;
	for(j=1;j<=w;j++)
		set[0][j]=0;
	for(it=s.begin(),i=1;it!=s.end(),i<=n;it++,i++)
	{
		for(j=1;j<=w;j++)
		{
			if(*it>j)
				set[i][j]=set[i-1][j];
			else
			{
				if(set[i-1][j]==1)
					set[i][j]=1;
				else
					set[i][j]=set[i-1][j-*it];
			}
		}
	}
	if(set[n][w]==1)
		cout<<endl<<"Subset is present which sum is "<<w<<endl;
	else
		cout<<"Subset is not present which sum is "<<w<<endl;
	cout<<endl<<"the subset is : ";
	j=w;
	for(i=n;i>=1;i--)
	{	
		if(set[i][j]!=set[i-1][j])
		{
			cout<<a[i-1]<<" ";
			j -=a[i-1];
		}
	}
	cout<<endl;
return 0;
}