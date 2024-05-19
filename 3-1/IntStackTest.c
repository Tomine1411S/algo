// int�^�X�^�b�NIntStack�̗��p��

#include <stdio.h>
#include "IntStack.h"

int main(void)
{
	IntStack s;

	if (Initialize(&s, 64) == -1)
	{
		puts("error!");
		return 1;
	}

	int menu, x;

	

	for (int i = 0; i < 1; i++)
	{
		scanf("%d", &menu);

		if (menu == 1)
		{ /*--- push ---*/
			scanf("%d", &x);
			if (Push(&s, x) == -1)
			{
				puts("push failed");
			}
			else
			{
				printf("%d", x);
			}
			menu = -1;
		}
		else if (menu == 2)
		{ /*--- pop ---*/
			if (Pop(&s, &x) == -1)
			{
				puts("pop failed");
			}
			else
			{
				printf("%d\n", x);
			}
			menu = -1;
		}
		else if (menu == 3)
		{ /*---  peek  ---*/
			if (Peek(&s, &x) == -1)
			{
				puts("peek failed");
			}
			else
			{
				printf("%d\n", x);
			}
			menu = -1;
		}
		else if (menu == 4)
		{ /*--- show ---*/
			Print(&s);
			menu = -1;
		}
		else if (menu == 5)
		{
			Clear(&s);
			printf("%d", Size(&s));
			menu = -1;
		}
		else if (menu == 6)
		{
			printf("%d", Capacity(&s));
			menu = -1;
		}
		else if (menu == 7)
		{
			printf("%d", Size(&s));
			menu = -1;
		}
		else if (menu == 8)
		{
			printf("%d", IsEmpty(&s));
			menu = -1;
		}
		else if (menu == 9)
		{
			printf("%d", IsFull(&s));
			menu = -1;
		}
		else if (menu == 10)
		{
			printf("%d", Search(&s, x));
			menu = -1;
		}
		else if (menu < 11 || menu > 0)
		{
			i = 1;
		}
	}

	Terminate(&s);

	return 0;
}
