#include<iostream>
using namespace std;

int main()
{
	int i,j,k,d,mc,n=5,min;
	int di[]={5,4,6,2,7},C[5][5]={0},K[5][5]={0};
	for(d=1;d<n-1;d++)
	{
		for(i=1;i<n-d;i++)
		{
			j=i+d;
			min=32767;
			for(k=i;k<j;k++)
			{
				mc=C[i][k]+C[k+1][j]+(di[i-1]*di[k]*di[j]);
				if(mc<min)
				{
					min=mc;
					K[i][j]=k;
				}
			}
			C[i][j]=min;
		}
	}
	cout<<"Minimum number of Multiplication : "<<C[1][n-1]<<endl;
	return 0;
}