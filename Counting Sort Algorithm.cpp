#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int i,n,k,mx;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    mx=*max_element(v.begin(),v.end());
    k=mx+1;
    vector<int> ct(k,0);
    for(i=0;i<n;i++)
        ct[v[i]]++;
    for(i=1;i<k;i++)
        ct[i]=ct[i]+ct[i-1];
    vector<int> a(n);
    for(i=n-1;i>=0;i--)
    {
        a[--ct[v[i]]]=v[i];
    }
    for(i=0;i<n;i++)
        v[i]=a[i];
    for(i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}
