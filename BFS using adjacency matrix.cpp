#include<iostream>
#include<queue>
#include<fstream>
#define white 1
#define gray 2
#define black 3
using namespace std;

int adj[100][100]={0},color[100]={0};


void bfs(int node, int n)
{
    int i;
    queue<int> q;
    q.push(node);
    for(i=0;i<n;i++)
        color[i]=white;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        color[x]=gray;
        cout<<x<<" ";
        for(i=0;i<n;i++)
        {
            if(adj[x][i]==1 && color[i]!=black)
                q.push(i);
        }
        color[x]=black;
    }
    cout<<endl;
}


int main()
{
    freopen("input.txt","r",stdin);
    int n,m,u,v,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    bfs(0,n);
    return 0;
}
