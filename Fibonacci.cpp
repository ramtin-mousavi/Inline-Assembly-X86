
int fibonacci(int n) {
	int result;

	__asm {
		mov ebx, n;
		cmp ebx, 0;
		je CONDITION1

			cmp ebx, 1;
		je CONDITION1

			dec ebx;
		mov ecx, ebx;

		mov ebx, 1;
		mov eax, 1;

	forloop:
		mov edx, ebx;
		mov ebx, eax;
		add eax, edx;
		loop forloop

			jmp CONDITION2

			CONDITION1 :
		mov result, 1;
		jmp CONDITION3

			CONDITION2 :
		mov result, eax;
	CONDITION3:

	}
	return result;
}
