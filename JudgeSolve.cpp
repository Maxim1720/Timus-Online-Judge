#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {

	long long unsigned num = 0;
	vector<double> sqrts;

	while (scanf_s("%llu", &num) != EOF) {
		sqrts.push_back(sqrt(double(num)));
	}
	for (int i = sqrts.size() - 1;i >= 0;i--)
	{
		printf("%.4lf\n",sqrts[i]);
	}

}

double SquareRoot(double kek) {
	double num = kek;
	double root = num / 2;
	double eps = 0.01;
	int iter = 0;
	while (root - num / root > eps) {
		iter++;
		root = 0.5 * (root + num / root);
	}
	return root;
}

int StrToInt(string s)
{
	int temp = 0; // число
	int i = 0;
	int sign = 0; // знак числа 0- положительное, 1 — отрицательное
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] >= 0x30 && s[i] <= 0x39)
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1)
		temp = -temp;
	return(temp);
}


 

//3-е задание первого тома
/*
int StrToInt(char* str) {

	int temp = 0; // число
	int i = 0;
	int sign = 0; // знак числа 0- положительное, 1 — отрицательное
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (str[i] >= 0x30 && str[i] <= 0x39)
	{
		temp = temp + (str[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1) {
		temp = -temp;
	}
	return(temp);


}


float InversSquareRoot(float x) {
	float xhalf = 0.5f * x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - (xhalf * x * x));
	return x;
}

float square_root(double num) {
	if (num == 1) {
		return 1;
	}
	double root = 0.5f * num;
	double eps = 0.01;
	while (root - num / root > eps) {
		root = 0.5 * (root + num / root);
	}
	return root;
}

int main() {
	int x;
	char str[256];
	char s[1];
	s[0] = ' ';
	while () {

		x = StrToInt(strcat(s, str));
		if (x >= 0 && x <= powf(10, 18)) {
			printf("root = %.4f", square_root(x));
		}
	}

	printf("x = ");
	gets_s(str, 256);
	str
}

*/

/*

int** Arr = NULL; // Матрица исходная
int M, N; //Размеры матрицы
long* temp, * temp2; //временные массивы для вывода результатов работы поиска и сортировки
int num;// Число для поиска

int LinearSearch(int size)
{

	for (int i = 0;i < size;i++) {
		if (temp2[i] == num) {
			return i;
		}
	}
	return -1;
}
int BinarySearch(int size) //Бинарный поиск
{

	int begIndex = 0, endIndex = size - 1;
	int mid = (begIndex + endIndex) / 2;
	while (begIndex <= endIndex)
	{
		mid = (endIndex + begIndex) / 2;
		if (num < temp[mid])
		{
			endIndex = mid - 1;
		}
		else if (num > temp[mid])
		{
			begIndex = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;

}
void BubbleSort(int size) //Пузырьковая сортировка
{
	bool NotSorted = true;//Логическая переменная, отвечающая за отсортированность массива.
	while (NotSorted) {
		NotSorted = false;
		for (int i = 0;i < size;i++) {
			if (temp[i] < temp[i - 1]) {
				float tmp;
				tmp = temp[i];
				temp[i] = temp[i - 1];
				temp[i - 1] = tmp;
				//delete(&tmp);
				NotSorted = true; //Если сортировать больше нечего, цикл не достигнет этого участка и процедура завершит свою работу
			}
		}
	}
}
void NotDuplicate(int* tmp, int size) {
	srand((unsigned)time(NULL));
	bool NotDuplicate = true;
	while (NotDuplicate) {
		NotDuplicate = false;
		for (int i = 0;i < size - 1;i++) {
			for (int j = i + 1;j < size;j++) {
				if (tmp[i] == tmp[j]) {
					tmp[j] = rand() % 3000 - 1000;
					NotDuplicate = true;
				}
			}
		}
	}
}

void FillArr() {
	int* newTemp = new int[M * N];
	for (int i = 0;i < M * N;i++) {
		newTemp[i] = rand() % 200 - 100;
	}
	NotDuplicate(newTemp, M * N);

	for (int i = 0, k = 0;i < M || k < M * N;i++) {
		for (int j = 0;j < N;j++) {
			Arr[i][j] = newTemp[k++];
		}
	}
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			printf(" %4d", Arr[i][j]);
		}
		printf("\n");
	}

}



int main() {
	setlocale(LC_ALL, "rus");


	int index, index2; //Индекс искомого числа
	printf("M(rows) = ");
	scanf_s("%d", &M); //Инициализация количества строк
	printf("N(columns) = ");
	scanf_s("%d", &N); //Инициализация количества столбцов
	printf("Searching num = ");
	scanf_s("%d", &num);

	//Динамическое выделение памяти для массива 
	Arr = new int* [M];           //Для строк
	for (int i = 0;i < M;i++) {   //Для столбцов
		Arr[i] = new int[N];
	}

	FillArr();//Заполнение и вывод массива рандомными значениями

	std::cout << "\t\t\t\t______Поиск в строках______" << std::endl;
	temp = new long[N]; //массив для изъятия строки/столбца с дальнейшей его сортировкой
	temp2 = new long[N];
	for (int i = 0;i < M;i += 2) { //перебор всех строк и проверка на наличие искомого элемента

		for (int j = 0;j < N;j++) {
			temp2[j] = temp[j] = Arr[i][j];
		}
		index2 = LinearSearch(N);
		BubbleSort(N);
		index = BinarySearch(N);
		if (index2 >= 0 && index >= 0)
		{
			std::cout << i + 1 << " строка: " << std::endl;
			std::cout << "\tОтсортированная строка: ";
			for (int k = 0;k < N;k++) {
				std::cout << temp[k] << " ";
			}
			std::cout << "\n\tНеотсортированная строка: ";

			for (int k = 0;k < N;k++) {
				std::cout << temp2[k] << " ";
			}
			std::cout << "\n";
			std::cout << "\tиндекс в отсортированной = " << index + 1 << " - бинарный поиск" << std::endl;
			std::cout << "\tИндекс в неотсортированной = " << index2 + 1 << " - последовательный поиск" << std::endl;


		}
		else {
			std::cout <<"\n"<< i + 1 << " строка: \n\tне найдено..." << std::endl;
		}
	}

	std::cout << "\n\n\n";
	std::cout << "\t\t\t\t______Поиск в столбцах______" << std::endl;
	temp = new long[M];
	temp2 = new long[M];

	for (int i = 0;i < N;i += 2) {
		for (int j = 0;j < M;j++) {
			temp2[j] = temp[j] = Arr[j][i]; //Заполнение временных массивов
		}

		index2 = LinearSearch(M);
		BubbleSort(M);
		index = BinarySearch(M);
		if (index2 >= 0 && index >= 0)
		{
			std::cout << i + 1 << " столбец: " << std::endl;
			std::cout << "\tотсортированный столбец: ";
			for (int k = 0;k < M;k++) {
				if (temp[k] == -21) {
					std::cout << num << " ";
				}
				else {
					std::cout << temp[k] << " ";
				}
			}
			std::cout << "\n\tНеотсортированный столбец: ";

			for (int k = 0;k < M;k++) {
				if (temp2[k] == -21) {
					std::cout << num << " ";
				}
				else {
					std::cout << temp2[k] << " ";
				}
			}
			std::cout << "\n";
			std::cout << "\tиндекс в отсортированном = " << index + 1 << " - бинарный поиск" << std::endl;
			std::cout << "\tИндекс в неотсортированном = " << index2 + 1 << " - последовательный поиск" << std::endl;
		}
		else {
			std::cout << "\n" << i + 1 << " столбец: \n\tне найдено..." << std::endl;
		}

	}
	system("pause");
	

}
*/



