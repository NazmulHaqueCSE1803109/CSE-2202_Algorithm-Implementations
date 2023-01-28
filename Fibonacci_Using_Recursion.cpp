#include<iostream>
using namespace std;

int sum;

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	
	sum=fib(n-1)+fib(n-2);

	return sum;
}

int main()
{
	int n;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}