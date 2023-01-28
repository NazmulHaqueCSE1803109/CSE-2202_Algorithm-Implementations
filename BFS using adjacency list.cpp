#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#define white 1
#define gray 2
#define black 3
using namespace std;

int n,m;
vector<int> vec[100];

void bfs(int x)
{
    int i;
    queue<int> q;
    q.push(x);
    int color[n];
    for(i=0;i<n;i++)
        color[i]=white;

    while(!q.empty())
    {
        int el=q.front();
        q.pop();
        color[el]=gray;
        cout<<el<<" ";
        for(i=0;i<vec[el].size();i++)
        {
            if(color[vec[el][i]]==white)
            {
                q.push(vec[el][i]);
                color[vec[el][i]]=gray;
            }
        }
        color[el]=black;
    }
}

int main()
{
    int u,v,i,j;
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    bfs(0);
    return 0;
}
