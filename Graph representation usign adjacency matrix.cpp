#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int a[100][100];

int main()
{

    freopen("input.txt","r",stdin);
    int node,edge,i,j;
    cin>>node>>edge;
    int n1,n2;
    for(i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        a[n1][n2]=1;
        a[n2][n1]=1;
    }
    for(i=0;i<node;i++)
    {
        for(j=0;j<node;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
