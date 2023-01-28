#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucket(vector<int>& a, int n, int pos)
{
    vector<vectot<int> > v (10,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        v[(a[i]/pos)%10][i]=a[i];
    }
}

int main()
{
    int n,i,j;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    int max=*max_element(a.begin(),a.end());
    for(i=1;max/i>0;i *=10)
    {
        bucket(a,n,i);
    }
}
