#include<iostream>
#include<fstream>
using namespace std;

int a[100][100];

int main()
{
    freopen("input.txt","r",stdin);
    int node,edge,i,j,n1,n2;
    cin>>node>>edge;
    for(i=0;i<edge;i++)
    {
        cin>>n1>>n2;
        a[n1][n2]=1;
        a[n2][n1]=1;
    }
    for(i=0;i<node;i++)
    {
        cout<<i<<"-> ";
        for(j=0;j<node;j++)
        {
            if(a[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
