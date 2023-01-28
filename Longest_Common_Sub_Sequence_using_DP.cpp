#include<iostream>
using namespace std;

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size(),i,j;
	int s[l1+1][l2+1];
	for(i=0;i<l1;i++)
		s[i][0]=0;
	for(j=0;j<l2;j++)
		s[0][j]=0;
	for(i=1;i<=l1;i++)
	{
		for(j=1;j<=l2;j++)
		{
            if(s1[i]==s2[j])
            	s[i][j]=1+s[i-1][j-1];
            else
            	s[i][j]=max(s[i][j-1],s[i-1][j]);
		}
	}
	cout<<"length of longest common sub_sequence is : "<<s[l1][l2]<<endl;
return 0;
}