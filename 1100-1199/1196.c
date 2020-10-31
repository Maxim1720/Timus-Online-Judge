#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

bool binarySerch(long arr[], int size, int x)
{
	int end = size;
	int beg = 0;
	int mid = beg + (end-beg)/2;
	
	
	while(beg<=end)
	{
		mid = beg + (end-beg)/2;
		if(arr[mid] == x)
		{
			return true;
		}
		if(arr[mid] < x)  //N*log(N)
		{
			beg = mid+1;
		}
		else
		{
				end = mid-1;
		}
	}
	return false;
}

int main()
{
	int N;
	int M;
	 long *stYears;
	 long *prYears;
	
	
	scanf("%d",&N);
	prYears = ( long*) malloc(sizeof( long) * N);
	for(int i=0;i<N;i++)
	{
		scanf("%lu",&prYears[i]); //N операций
	}
	
	scanf("%d",&M);
	stYears = (long*) malloc(sizeof( long) * M);
	for(int i=0;i<M;i++)
	{
		scanf("%lu",&stYears[i]); //M операций
	}
	
	int count = 0;
	
	for(int i=0;i<M;i++)
	{
		if(stYears[i]<=prYears[N-1] || stYears[i] >= prYears[0])
		{
			count+=binarySerch(prYears,N,stYears[i]);
		}
	}
	
	printf("%d\n",count);
	
}
