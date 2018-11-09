
int divide(int a, int b) {
	int result;
	
	__asm {
		mov eax , 0 // Result
		mov ebx , b // Divisor
		mov edx , a // Result Of Each Step (Dividand)

		sub edx , ebx 
		cmp edx , 0
		jl Label2

		Label1:
			inc eax
			sub edx , ebx 
			cmp edx , 0
			jge Label1

		Label2:
			mov result , eax


	}
}