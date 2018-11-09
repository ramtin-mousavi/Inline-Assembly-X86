#include <iostream>
#define MAXSIZE 1000
using namespace std;


// ---------------------------- HW 2 ---------------------------- //

char my_str[MAXSIZE];

void reverse_words(void)
{
	// Reverse Every Word Of A Given String
	__asm
	{
		lea ebx, my_str						// Move my_str To ebx (By Refr.)
		mov ecx, 0							// Initialize offset Pointer

		Start:
			mov esi, ecx					// start_index = offset For Each Step


		Main_Loop :							// Push Characters To Stack Untill Reaching Space Or Null
			mov al, byte ptr[ebx + ecx * 1]
			cmp al, 0
			je Reverse_Loop
			cmp al, 32
			je Reverse_Loop

			movzx eax, al					// Extend al (8bit) To eax (32bit) So We Can Push It To Stack!
			push eax
			inc ecx							// Increment offset Pointer
			jmp Main_Loop


		Reverse_Loop :						// Pop One Item From Stack, Put It In start_index Place

			cmp esi, ecx					// Do While start_index Reachs offset 
			je Skip_Spaces					// At The End, Skip Additional Spaces
			pop eax
			mov byte ptr[ebx + esi * 1], al
			inc esi							// Increment start_index
			jmp Reverse_Loop


		Skip_Spaces :
			mov al, byte ptr[ebx + ecx * 1]
			cmp al, 0
			je End_Of_String				// Check If It Is The End Of String, Go To End Label
			cmp al, 32
			jne Start
			inc ecx							// Skip All Additional Spaces
			jmp Skip_Spaces


		End_Of_String :						// Put A Null Character At The End Of The String
			mov byte ptr[ebx + ecx * 1], 0
	}


}

// ---------------------------- Test Cases ---------------------------- //



int main() {

	// ++++++++++ Test HW 2 ++++++++++ //

	// TA Example:
	strcpy_s(my_str, 100, "The verification of the Stable Release Update has completed");
	printf("\nYour Example Before Applying reverse_words():\n%s\n\n", my_str);
	reverse_words();
	printf("Your Example After Calling reverse_words() Function:\n%s\n\n--------------------", my_str);


	// Scan Input From User
	int arraySize;
	cout << "\nNow It's Your Turn To Test reverse_words() With Your Test Case!\n\n";
	cout << "Please Enter The (Max) Size Of Your String: ";
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


	//Copy The Scanned String Into my_str Variable Which The Function Will Effect On It (By Refrence)
	strcpy_s(my_str, arraySize, cpy);

	printf("\nYour String Before Applying reverse_words():\n%s\n\n", my_str);
	reverse_words();
	printf("The String After Calling reverse_words() Function:\n%s\n\n", my_str);

	system("PAUSE");

	return 0;
}
