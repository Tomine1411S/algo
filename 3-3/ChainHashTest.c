// チェインハッシュChainHashの利用例

#include <stdio.h>
#include "Member.h"
#include "ChainHash.h"

/*--- メニュー ---*/
typedef enum
{
	TERMINATE,
	ADD,
	DELETE,
	SEARCH,
	CLEAR,
	DUMP
} Menu;

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
	int ch;

	for (int i = 0; i < 1; i++)
	{
		printf("(1)追加 (2)削除 (3)探索 (4)全削除 (5)ダンプ (0)終了：");
		scanf("%d", &ch);
		if (ch < TERMINATE || ch > DUMP)
		{
			i = -1;
		}
		else
		{
			return (Menu)ch;
		}
	}
	return (Menu)ch;
}

/*--- メイン ---*/
int main(void)
{
	Menu menu;		// メニュー
	ChainHash hash; // ハッシュ表

	Initialize(&hash, 13); // ハッシュ表の初期化

	do
	{
		int result;
		Member x;
		Node *temp;
		menu = SelectMenu();

		if (menu == ADD)
		{
			/*--- データの追加 ---*/
			x = ScanMember("追加", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash, &x);
			if (result)
				printf("\aエラー：追加に失敗しました（%s）。\n",
					   (result == 1) ? "登録ずみ" : "メモリ不足");
			break;
		}
		if (menu == DELETE)
		{
			/*--- データの削除 ---*/
			x = ScanMember("削除", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("\aエラー：その番号のデータは存在しません。\n");
			break;
		}
		if (menu == SEARCH)
		{
			/*--- データの探索 ---*/
			x = ScanMember("探索", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("\a探索に失敗しました。\n");
			else
			{
				printf("探索に成功しました：");
				PrintLnMember(&temp->data);
			}
			break;
		}
		if (menu == CLEAR)
		{
			/*--- 全データの削除 ---*/
			Clear(&hash);
			break;
		}
		if (menu == DUMP)
		{
		DUMP: /*--- ハッシュ表のダンプ ---*/
			Dump(&hash);
			break;
		}
	}

	while (!Terminate);(&hash); // ハッシュ表の後始末

	return 0;
}
