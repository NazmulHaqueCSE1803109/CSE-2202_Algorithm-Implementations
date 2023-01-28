#include<iostream>
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		int f=1;
		cin>>n;
		char ch[2][n];
		for(i=0;i<2;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>ch[i][j];
			}
		}
		i=0;j=0;
		while(j!=n && i<=1)
		{
           if(i==0)
           {
           	if(ch[i+1][j+1]!='0' && ch[i][j+1]!='0')
           	{
           		cout<<"NO"<<endl;f=0;
           		break;
           	}
           	else
           	{
           		if(ch[i][j+1]=='0')
           			j++;
           		else
           			{
           				i++;j++;
           			}
           	}
           }
           else
           {
           	if(ch[i-1][j+1]!='0' && ch[i][j+1]!='0')
           	{
           		cout<<"NO"<<endl;f=0;
           		break;
           	}
           	else
           	{
           		if(ch[i][j+1]=='0')
           			j++;
           		else
           		{
           			i--;j++;
           		}
           	}
           }
		}
		if(f==1)
			cout<<"YES"<<endl;
	}
	return 0;
}