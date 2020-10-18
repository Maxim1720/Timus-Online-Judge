#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	char str[51] = {'\0'};
	int counts[256] = {0};
	
	char c;
	int l=0, size=0;
	int max_i = 0;
	
	while((c = getchar())!='\n')
	{
		str[l++] = c;
		
		size++;
	}
	
	
	
	
	for(int i=0;i<size;i++)
	{
		counts[(int)str[i]]++;
		
		if(counts[(int)str[i]]> counts[(int)str[max_i]])
		{
			max_i = i;
		}
	}
	printf("%c\n",(char)str[max_i]);
	
}






















