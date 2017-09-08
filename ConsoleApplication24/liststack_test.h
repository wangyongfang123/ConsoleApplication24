#pragma once
#include<stdio.h>
#include"list_stack.h"
void instructions(void);
void printfElement(char data)
{
	printf("%c\t", data);
}

int main()
{
	liststackPtr stackPtr = 0;  /* points to stack top */
	int choice = 0;
	char value;

	instructions();
	printf("? ");
	scanf("%d", &choice);

	while (choice != 4) {

		switch (choice) 
		{
		case 1:      /* push value onto stack */
			printf("Enter an integer: ");
			scanf("\n%c", &value);
			push(&stackPtr, value);
			//printStack(stackPtr, printfElement);
			break;
		case 2:      /* pop value off stack */
			if (!isEmpty(stackPtr))
				printf("The popped value is %c.\n",
					pop(&stackPtr));

			//printStack(stackPtr, printfElement);
			break;
		case 3:

			printf("stack elements:\n");
			printStack(stackPtr, printfElement);
			printf("\n");
			break;
		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}

	printf("End of run.\n");
	return 0;
}
void instructions(void)
{
	printf("Enter choice:\n"
		"1 to push a value on the stack\n"
		"2 to pop a value off the stack\n"
		"3 show all elements in the stack\n" 
		"4 to end program\n");
}