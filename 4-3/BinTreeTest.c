// ?Q???T???????p??

#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- ???j???[ ---*/
typedef enum
{
	SEARCH,
	ADD,
	REMOVE,
	PRINT,
	TERMINATE

} Menu;

/*--- ???j???[?I?? ---*/
Menu SelectMenu(void)
{
	int ch;

	do
	{
		printf("\n");
		scanf("%d", &ch);
		if (ch == 6){
			break;
		}
	} while (ch < SEARCH || ch > TERMINATE);
	return (Menu)ch;
}

/*--- ???C????? ---*/
int main(void)
{
	Menu menu;
	BinNode *root = NULL; // ?Q???T?????????|?C???^
	int terminate_flag = 0;

	while (terminate_flag == 1)
	{
		Member x;
		BinNode *temp;
		menu = SelectMenu();
		if (menu == TERMINATE)
		{
			terminate_flag = 1;
		}
		else
		{

			if (menu == ADD)
			{
				x = ScanMember("?}??", MEMBER_NO | MEMBER_NAME);
				root = Add(root, &x);
				break;
			}
			/*--- ?m?[?h??? ---*/
			else if (menu == REMOVE)
			{
				x = ScanMember("??", MEMBER_NO);
				Remove(&root, &x);
				break;

				/*--- ?m?[?h??T?? ---*/
			}
			else if (menu == SEARCH)
			{
				x = ScanMember("?T??", MEMBER_NO);
				if ((temp = Search(root, &x)) != NULL)
					PrintLnMember(&temp->data);
				break;

				/*--- ?S?m?[?h??\?? ---*/
			}
			else if (menu == PRINT)
			{
				puts("");
				PrintTree(root);
				break;
			}
		}
	};

	FreeTree(root);

	return 0;
}
