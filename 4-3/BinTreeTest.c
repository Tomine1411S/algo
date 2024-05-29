// ?Q???T???????p??

#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

/*--- ???j???[ ---*/
typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

/*--- ???j???[?I?? ---*/
Menu SelectMenu(void)
{
	int ch;

	do {
		printf("\n");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > PRINT);
	return (Menu)ch;
}

/*--- ???C????? ---*/
int main(void)
{
	Menu    menu;
	BinNode *root = NULL;		// ?Q???T?????????|?C???^

	do {
		Member x;
		BinNode *temp;

		switch (menu = SelectMenu()) {
		 /*--- ?m?[?h??}?? ---*/
		 case ADD :
				x = ScanMember("?}??", MEMBER_NO | MEMBER_NAME);
				root = Add(root, &x);
				break;

		 /*--- ?m?[?h??? ---*/
		 case REMOVE :
				x = ScanMember("??", MEMBER_NO);
				Remove(&root, &x);
				break;

		 /*--- ?m?[?h??T?? ---*/
		 case SEARCH :
				x = ScanMember("?T??", MEMBER_NO);
				if ((temp = Search(root, &x)) != NULL)
					PrintLnMember(&temp->data);
				break;

		 /*--- ?S?m?[?h??\?? ---*/
		 case PRINT :
				puts("");
				PrintTree(root);
				break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);

	return 0;
}
