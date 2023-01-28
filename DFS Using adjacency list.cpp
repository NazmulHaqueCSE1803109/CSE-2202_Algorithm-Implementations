#include<iostream>
#include<vector>
#include<fstream>
#define white 1
#define gray 2
#define black 3
using namespace std;

int node,edge;
vector<int> vec[100];
int color[100]={0};


void dfs(int x)
{
    int i;
    color[x]=gray;
    cout<<x<<" ";
    for(i=0;i<vec[x].size();i++)
    {
        if(color[vec[x][i]]==white)
            dfs(vec[x][i]);
    }
    color[x]=black;
}


int main()
{
    int u,v,i,j;
    freopen("input","r",stdin);
    cin>>node>>edge;
    for(i=0;i<edge;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(i=0;i<node;i++)
        color[i]=white;
    cout<<"traverse the graph using dfs : ";
    dfs(0);
    cout<<endl;
    return 0;
}
