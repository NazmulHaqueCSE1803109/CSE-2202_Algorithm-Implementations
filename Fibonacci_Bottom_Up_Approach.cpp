#include<iostream>
#include<vector>
using namespace std;

int fib(int n)
{
	vector<int> v(n+1);
	int i;
	v[0]=0;v[1]=1;
	for(i=2;i<=n;i++)
	{
		v[i]=v[i-1]+v[i-2];
	}
  return v[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}