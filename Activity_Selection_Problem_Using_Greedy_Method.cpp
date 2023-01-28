#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.second<b.second;
}

int main()
{
	int i,n,x,y,k;
	vector<pair<int,int> > v;
	cout<<"Enter number of activity : ";
	cin>>n;
	cout<<"Enter the value of start time and finish time of a activity :"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	cout<<"activity before sorting :"<<endl;
	for(i=0;i<n;i++)
		cout<<v[i].first<<"\t"<<v[i].second<<endl;
	sort(v.begin(),v.end(),sortbysec);
	cout<<"activity after sorting :"<<endl;
	for(i=0;i<n;i++)
		cout<<v[i].first<<"\t"<<v[i].second<<endl;
	cout<<"Selected Activity :"<<endl;
	cout<<v[0].first<<"\t"<<v[0].second<<endl;
	k=0;
	i=1;
	while(i<n)
	{
		if(v[i].first>=v[k].second)
			{
				cout<<v[i].first<<"\t"<<v[i].second<<endl;
				k=i;
			}
		i++;
	}
	return 0;
}