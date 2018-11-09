

int power(int a, int b) {
	int result;
	__asm {

		mov eax, b // counter of outer loop
		mov ebx, a // result of each step
		mov esi, a

		OuterLoop :

		mov edx, ebx
			mov ebx, 0

			//mov ecx , a //counter of product
			mov ecx, esi

			InnerLoop :
		add ebx, edx
			loop InnerLoop

			//mov edx , ebx 
			//mov ebx , 0

			dec eax
			cmp eax, 1
			jne OuterLoop

			mov result, ebx


	}

	return result;
}