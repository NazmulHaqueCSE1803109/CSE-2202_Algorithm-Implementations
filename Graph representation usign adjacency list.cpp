#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
    int n,m,u,v,i,j;
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    vector<int> vec[n];
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(i=0;i<n;i++)
    {
        cout<<i<<"-> ";
        for(j=0;j<vec[i].size();j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
