#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool sortbysec(const pair<int,int>& a, const pair<int,int>& b)
{
	return (a.second<b.second);
}

int main()
{
	int i,j,n,p,w,cp;
	cout<<"Enter number of item : ";
	cin>>n;
	vector<pair<int,int> > v;
	cout<<"Enter the value of profit and weight : ";
	for(i=0;i<n;i++)
	{
		cin>>p>>w;
		v.push_back(make_pair(p,w));
	}
	sort(v.begin(),v.end(),sortbysec);
	cout<<"Enter the maximum capacity of knapsack : ";
	cin>>cp;
    int kp[n+1][cp+1];
    for(i=0;i<=n;i++)
    	kp[i][0]=0;
    for(j=1;j<=cp;j++)
    	kp[0][j]=0;
    for(j=1;j<=cp;j++)
    {
    	if(v[0].second>j)
    		kp[1][j]=kp[0][j];
    	else
    		kp[1][j]=v[0].first;
    }
    for(i=2;i<=n;i++)
    {
    	for(j=1;j<=cp;j++)
    	{
    		if(v[i-1].second>j)
    			kp[i][j]=kp[i-1][j];
    		else
    			kp[i][j]=max(kp[i-1][j],v[i-1].first+kp[i-1][j-v[i-1].second]);
    	}
    }

    cout<<"maximum profit is : "<<kp[n][cp]<<endl;
    cout<<"Selected profit and weight item are : "<<endl;
    j=cp;
    for(i=n;i>=1;i--)
    {
    	if(kp[i][j]!=kp[i-1][j])
    	{
    		cout<<"profit: "<<v[i-1].first<<"\t"<<"weight: "<<v[i-1].second<<endl;
    		j -=v[i-1].second;
    	}
    }
    return 0;
}