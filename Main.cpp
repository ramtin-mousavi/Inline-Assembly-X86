#include <iostream>
using namespace std;

int fibonacci(int n);


int main()
{
	int inp;
	printf("Insert Positive Integer n To Calculate Fibonacc (n): ");
	cin >> inp;
	printf("Fibo(%d) = %d\n\n", inp, fibonacci(inp));

	getchar();
	getchar();


	return 0;

}
