#include <iostream>
using namespace std;



// ---------------------------- HW 1 ---------------------------- //

 int is_prime(double n) {

	int result;

	__asm
	{
		// Calculate Square Root Of n

		movsd xmm0, n			// Move n To Double Percision Register
		sqrtsd xmm0, xmm0		// Calculate Square Root Of n
		cvtpd2dq xmm0, xmm0		// Cast The Result To Integer
		movd esi, xmm0			// Move Above Integer To A General Purpose Register

		inc esi

		// Detect Whether The n Is Prime Or Not ?  (eax = Radical n) :

		movsd xmm0, n
		cvtpd2dq xmm0, xmm0
		movd ebx, xmm0			// Store n In Register To Avoid Fetching From Memory In Each Iteration
								// Causes Better Performance And Fewer Clock Cycles

		cmp ebx, 1
		jle Assertion			// Assert n>=2

		mov eax, 1

		OuterLoop:				// Loop: for i in range (2,sqrt(n))

			mov edx, ebx
			inc eax				// Increment eax After Each Iterate

			cmp eax, esi
			je IsPrime			// If eax = radical n , Jump To Not Prime Label

		InnerLoop :

			sub edx, eax		// n = n-i
			cmp edx, 0			// compare n and 0
			jg InnerLoop


		// Reach Here When Less Than Or Equal To 0 :

		cmp edx, 0
		je NotPrime				// If Result Is 0, n Is Dividable To A Number
		jmp OuterLoop			// Otherwise, Jump To OuterLoop (for Loop)


		Assertion :
			mov result, -1
			jmp Done

		IsPrime :
			mov result, 1
			jmp Done

		NotPrime :
			mov result, 0
			jmp Done

		Done :

	}

	return result;
}




// ---------------------------- Test Cases ---------------------------- //
int main() {

	// ++++++++++ Test HW 1 ++++++++++ //

	// Scan Input From User
	int i;
	printf("Please Enter A 32bit Integer (Less Than 2147483647) To Calculate is_prime (input): ");
	cin >> i;

	if (is_prime(i) == -1) {printf("%d Is Not A Valid Number!\n", i);}
	else if (is_prime(i) == 1) {printf("%d Is Prime!\n", i);}
	else {printf("%d Is Not Prime!\n\n------------------------------", i);}


	system("PAUSE");

	return 0;
}




