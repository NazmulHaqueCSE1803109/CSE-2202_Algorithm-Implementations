#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int node,edge;

void floyad(vector<vector<int> >& vec (node, vector<int>(node,INT_MAX)))
{
	int i,j,k;
	for(i=0;i<node;i++)
	{
		for(j=0;j<node;j++)
		{
			for(k=0;k<node;k++)
			{
				if(vec[j][i]==INT_MAX || vec[i][k]==INT_MAX)
					continue;
				else if((vec[j][i]+vec[i][k])<vec[j][k])
				{
                    vec[j][k]=(vec[j][i]+vec[i][k]);
				}
			}
		}
	}
	//chechk negative edge weight ..
	for(i=0;i<node;i++)
		if(vec[i][i]<0)
		{
			cout<<"negative edge weight remains."<<endl;
			return;
		}

	for(i=0;i<node;i++)
	{
		for(j=0;j<node;j++)
			cout<<"distance from "<<i<<" to "<<j<<" is = "<<vec[i][j]<<endl;
		cout<<endl<<endl;
	}
}

int main()
{
	int u,v,w,i,j;
	freopen("input1.txt","r",stdin);
	cin>>node>>edge;
	vector<vector<int> > vec(node,vector<int>(node,INT_MAX));
	for(i=0;i<edge;i++)
	{
		cin>>u>>v>>w;
		// in this case use directed graph.
		vec[u][v]=w;
	}
	floyad(vec);
	return 0;
}
kjkj