//Копирование
#include <stdio.h>

void _1131()
{
	int count;
	long K,N;
	
	scanf("%li%li",&N,&K);
	
		long k = N-1, j = 1;                                      //Изначально данные для передачи хранятся в одном из компьютеров
                                                              //соответственно, количество "пустых" компов равно N-1
    
		count = 0;
		for(count = 0;(k-j)>=0 && j<K;count++)										//k 	- количество пустых компов
		{																			                    //j 	- количество компов с файлом
																					                    //count - кол-во часов передачи файла по всем компам
			k-=j;
			j<<=1;
			
		}
		
		double pop = k/(K*1.0);
		
		if(pop > (int)pop)
		{
			count++;
		}
		count+=(int) pop;
		printf("%d\n",count);
}

int main()
{
	_1131();
	return 0;
}

