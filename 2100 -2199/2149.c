#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>



int main(int argc, char **argv)
{
	int n, 				    			//количество голубей 
		string_size;					//размер каждой строки
	scanf("%d",&n); 
	string_size = 5*n-1;
	
	char str[string_size];				//строка с головами голубей 
										//(чтобы отличить ориетанцию каждого голубя, 
										//достаточно только направления клюва)
	
	scanf("%s",str);	  				//для решения задания не требуется ввод точно по размеру
	
	bool beaks[n];		  				//массив для хранения ориентаций каждого голубя
										//( true - право, false - лево)
	
	
	for(int i=0, j=0;i<string_size && j<n;i++)			
	{
		if(str[i] == 62)  //62 - код символа '>'
		{
			beaks[j++] = true;
		}
		else if(str[i] == 60) //60 - код символа '<'
		{
			beaks[j++] = false;
		}
		//_______
		/*инициализация массива направлений в 
		соответствии с позицией каждого голубя*/
		//_______
	}
	
	
	
	
	char p[string_size*2]; 						//массив для заполнения остальными частями тела голубей
	scanf("%s",p);
	
	int min = n;								//минимальное количество смен ориентаций голубей
	
	int count1=0,count2=0;						//первая переменная хранит количество смен в случаях если
												//первая половина не равна второй половине
												
												//вторая переменная хранит количество смен в случаях
												//когда нечетные одинаковы между собой и четные одинаковы
												//между собой
	
	for(int i=0;i<2;i++)
	{
		//i = 0 - false(лево) - первый голубь ДОЛЖЕН смотреть влево
		//i = 1 - true(право) - ориентир на то, что первый голубь смотрит вправо
		count1 = count2 = 0;
		bool tmp = i;
		
		for(int j=0;j<n;j++)
		{
			
			if(j==n/2)
			{
				tmp = !tmp;
			}
			if(beaks[j] != tmp)
			{
				count1++;
			}
			
			
		}
		
		for(int j=0;j<n;j++)
		{
			if((j+1)%2!=0)
			{
				if(beaks[j]!=i)
				{
					count2++;
				}
			}
			else
			{
				if(beaks[j]!= !i)
				{
					count2++;
				}
			}
		}
		
		if(count1 < count2)
		{
			if(count1<min)
			{
				min = count1;
			}
		}
		else
		{
			if(count2<min)
			{
				min = count2;
			}
		}
		
	}
	printf("\n%d\n\n",min);
	
	/*всего 4 варианта, когда ориентация голубей удовлетворит Дерихле:
	  половинки:	1)первая половина смотрит вправо, вторая смотрит влево
	  * 			2)наоборот
	  
	  через одного: 1)нечетные смотрят влево, четные - вправо
	  * 			2)наоборот
	  * 
	  Ориентируясь на эти случаи, 
	  можно проверять в каких случаях и сколько придется поворачивать голубей :)
	  **/
	
}
