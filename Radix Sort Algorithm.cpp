#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void count_sort(vector<int>& v, int n, int pos)
{
    int i;
    vector<int> ct(10,0);
    vector<int> a(n);
    for(i=0;i<n;i++)
        ct[(v[i]/pos)%10]++;
    for(i=1;i<10;i++)
        ct[i]=ct[i]+ct[i-1];
    for(i=n-1;i>=0;i--)
        a[--ct[(v[i]/pos)%10]]=v[i];
    for(i=0;i<n;i++)
        v[i]=a[i];
}

void radix_sort(vector<int>& v, int n)
{
    int i,mx,pos;
    mx=*max_element(v.begin(),v.end());
    for(pos=1;mx/pos>0;pos *=10)
    {
        count_sort(v,n,pos);
    }
    cout<<endl<<"after radix sort the sorting list is : ";
    for(i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,i,mx;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++)
        cin>>v[i];
    radix_sort(v,n);
    return 0;
}
