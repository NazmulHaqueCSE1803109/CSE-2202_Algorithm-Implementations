#include<iostream>
using namespace std;

int g[5][5]={
	{0,1,1,0,1},
	{1,0,1,1,1},
	{1,1,0,1,0},
	{0,1,1,0,1},
	{1,1,0,1,0}
};
int x[6]={0},n,i,j;


void nextvertex(int k)
{
   do{
       x[k]=(x[k]+1)%(n+1);
       if(x[k]==0)
       	 return;
       if(g[x[k-1]][x[k]]!=0)
       {
       	 for(j=1;j<k;j++)
       	 {
       	 	if(x[j]==x[k])
       	 		break;
       	 }
       	 if(j==k)
       	 {
       	 	if(k<n || (k==n && g[x[k]][x[1]]==1))
       	 	return;
       	 }
       	 
       }
   }while(true);
}


void hamiltonian(int k)
{
	do{
		nextvertex(k);
		if(x[k]==0)
			return;
		if(x[k]==n)
		{
			for(i=1;i<=n;i++)
				cout<<x[i]<<" ";
			cout<<endl;
		}
		else
			hamiltonian(k+1);

	}while(true);
}


int main()
{
	cout<<"Enter the number of vertex : ";
	cin>>n;
   hamiltonian(1);
   return 0;
}