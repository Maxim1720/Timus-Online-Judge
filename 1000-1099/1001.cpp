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