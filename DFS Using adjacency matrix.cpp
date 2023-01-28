#include<iostream>
#define white 1
#define gray 2
#define black 3
#include<fstream>

using namespace std;

int adj[100][100],n,m;
int color[100]={0};

void dfs(int x)
{
    int i;
    color[x]= gray ;
    cout<<x<<" ";
    for(i=0;i<n;i++)
    {
        if(adj[x][i]==1 && color[i]==white)
            dfs(i);
    }
    color[x]=black;
}

int main()
{
    int u,v,i,j;
    freopen("input.txt","r",stdin);

    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(i=0;i<n;i++)
        color[i]=white;
    dfs(0);
    cout<<endl;

    return 0;
}
