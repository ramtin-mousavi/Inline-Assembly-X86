#include <iostream>
using namespace std;

int fibonacci(int n);
int power(int a, int b);
int divide(int a, int b);

int main()
{
	int inp;
	printf("HW1--> Insert Positive Integer n To Calculate Fibonacc (n): ");
	cin >> inp;
	printf("Fibo(%d) = %d\n\n", inp, fibonacci(inp));

	int inp1, inp2;
	printf("HW2--> Insert 2 Positive Integers To Calculate a^b:\n");
	cin >> inp1;
	cin >> inp2;

	printf("%d^%d = %d\n\n", inp1, inp2, power(inp1, inp2));

	int inp3, inp4;
	printf("HW3--> Insert 2 Positive Integers To Calculate [a/b]:\n");
	cin >> inp3;
	cin >> inp4;

	printf("[%d/%d] = %d\n\n", inp3, inp4, divide(inp3, inp4));

	getchar();
	getchar();


	return 0;

}
