
#include <stdio.h>


int main(int argc, char **argv)
{
	int n, m;
	
	float N[10000] = {0};
	scanf("%d%d",&n,&m);
	
	float per = 1.0/(m*1.0) * 100;
	
	for(int i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		N[tmp-1]+=per;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%.2f%%\n",N[i]);
	}
	
}

