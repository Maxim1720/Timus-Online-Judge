#include <stdio.h>
#include <stdbool.h>


int main()
{
	char offers[10000];
	int count = 0;
	bool flag = true;
	while(!feof(stdin)/*count<50*/)
	{
		offers[count] = getchar();
		if(offers[count] == '!' || offers[count] == '?' || offers[count] == '.')
		{
			flag = true;
		}
		if(count>0 && offers[count-1] == '\n' && offers[count] == '-')
		{
			flag = true;
		}
		
		if(offers[count]>96 && offers[count]<123)
		{
			if(flag)
			{
				offers[count]-=32;
			}
		}
		
		if(offers[count]>64 && offers[count]<91)
		{
			if(!flag)
			{
				offers[count] += 32;
			}
			if(flag)
			{
				flag = false;
			}
		}
		count++;
	}
	
	
	printf("%s",offers);
}

