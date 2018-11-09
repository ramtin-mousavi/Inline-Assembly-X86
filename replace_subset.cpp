
#include "tchar.h"
#include <iostream>
using namespace std;

#define MAXSIZE 1000
#define FINDSIZE 100
#define REPLACESIZE 100


char my_str[MAXSIZE];
char str1[FINDSIZE];
char str2[REPLACESIZE];

char result[MAXSIZE];


void replace(void)
{  

	_asm {

		lea  esi, my_str
		mov  ebx, esi
		lea  esi, result
		mov  ecx, esi
		mov  esi, ebx
		lea  edi, str1


		Search :

			mov  al, [edi]
			cmp  al, 0
			je   Match
			cmp[esi], 0
			je   End
			cmp[esi], al
			jne  Mismatch
			inc  esi
			inc  edi
			jmp  Search


		Match :

			mov  ebx, esi
			dec  ebx
			lea  edi, str2


		Replace :

			mov  al, [edi]
			cmp  al, 0
			je   Next
			mov  esi, ecx
			mov[esi], al
			inc  ecx
			inc  edi
			jmp  Replace


		Mismatch :

			mov  esi, ebx
			mov  edi, ecx
			mov  al, [esi]
			mov[edi], al
			inc  ecx


		Next :

			lea  edi, str1
			inc  ebx
			mov  esi, ebx
			cmp[esi], 0
			jne  Search


		End :
	}


}

int main() {

	// TA Example:
	strcpy_s(my_str, 100, "Hello World! Hello Programming! :)");
	strcpy_s(str1, 10, "Hello");
	strcpy_s(str2, 10, "Hi");

	printf("\nYour Example Before Applying Function:\n%s\n\n", my_str);
	replace();
	printf("Your Example After Calling Function:\n%s\n\n--------------------\n\n", result);

	int arraySize;
	cout << "Now You Can Test HW By Yourself:\n";
	cout << "\nPlease Enter The (Max) Size Of Your String: ";
	cin >> arraySize;
	arraySize += 1;
	char *cpy;
	cpy = new char[arraySize];
	getchar();

	cout << "Please Enter Your String: ";
	fgets(cpy, arraySize, stdin);
	size_t ln = strlen(cpy) - 1;			//Remove Last \n 
	if (cpy[ln] == '\n')
		cpy[ln] = '\0';



	int findSize;
	cout << "\nPlease Enter The (Max) Size Of The String Which You Want To Be Replaced: ";
	cin >> findSize;
	findSize += 1;
	char *cpy1;
	cpy1 = new char[findSize];
	getchar();

	cout << "Please Enter The String Which You Want To Be Replaced: ";
	fgets(cpy1, findSize, stdin);
	size_t ln1 = strlen(cpy1) - 1;			//Remove Last \n 
	if (cpy1[ln1] == '\n')
		cpy1[ln1] = '\0';



	int replaceSize;
	cout << "\nPlease Enter The (Max) Size Of The String Which You Want To Replace It: ";
	cin >> replaceSize;
	replaceSize += 1;
	char *cpy2;
	cpy2 = new char[replaceSize];
	getchar();

	cout << "Please Enter The String Which You Want To Replace It: ";
	fgets(cpy2, replaceSize, stdin);
	size_t ln2 = strlen(cpy2) - 1;			//Remove Last \n 
	if (cpy2[ln2] == '\n')
		cpy2[ln2] = '\0';


	//Copy The Scanned String Into my_str Variable Which The Function Will Effect On It (By Refrence)
	strcpy_s(my_str, arraySize, cpy);
	strcpy_s(str1, findSize, cpy1);
	strcpy_s(str2, replaceSize, cpy2);

	printf("---------------\nBefore Applying Function:\n%s", my_str);
	replace();
	printf("\n---------------\nAfter Applying Function:\n%s\n\n", result);

	system("PAUSE");

	return 0;
}
