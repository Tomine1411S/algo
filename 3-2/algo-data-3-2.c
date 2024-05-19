// int�^�L���[IntQueue�̗��p��

#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
	IntQueue que;

	if (Initialize(&que, 10000) == -1)
	{
		puts("generate failed");
		return 1;
	}

	for (int i = 0; i < 1; i++)
	{
		int m, x;

		scanf("%d", &m);

		if (m == 0)
			i = -1;

		if (m == 1)
		{ /*--- Enque ---*/
			scanf("%d", &x);
			if (Enque(&que, x) == -1){
				puts("Enque failed");
			}else {
				printf("%d\n", x);
			}
			i = -1;
		}

		else if (m == 2)
		{ /*---  deque  ---*/
			if (Deque(&que, &x) == -1){
				puts(" deque failed");
			}else{
				printf("%d\n", x);
			}i = -1;
		}

		else if (m == 3)
		{ /*---  Peek  ---*/
			if (Peek(&que, &x) == -1)
				puts(" Peek Failed");
			else
				printf("%d\n", x);
			i = -1;
		}

		else if (m == 4)
		{ /*--- Show ---*/
			Print(&que);
			i = -1;
		}

		else if (m == 5)
		{
			Clear(&que);
			printf("%d",Size(&que));
			i = -1;
		}
		else if (m == 6)
		{
			printf("%d", Capacity(&que));
			i = -1;
		}
		else if (m == 7)
		{
			printf("%d", Size(&que));
			i = -1;
		}
		else if (m == 8)
		{
			printf("%d", IsEmpty(&que));
			i = -1;
		}
		else if (m == 9)
		{
			printf("%d", IsFull(&que));
			i = -1;
		}
		else if (m == 10)
		{
			printf("%d", Search(&que, x));
		}
		else if (m > 11 || m < 0) {
			i = -1;
		}
	}

	Terminate(&que);

	return 0;
}
