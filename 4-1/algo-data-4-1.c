# include <stdio.h>
# include <stdlib.h>
# include <math.h>


int main(void) {

    int height; //木の高さ
    scanf("%d", &height);
    
    if (height < 1 || height > 10) {
        printf("Error");
        return 10;
    }

    // ノードの総数を計算する
    int AllNode = (1 << height) - 1;

    // 配列の宣言
    int array[1050];
    for (int j = 0; j < AllNode; j++) {
        scanf("%d", &array[j]);
    }

    // ノードを順番に出力
    int index = 0;
    for (int i = 0; i < height; i++) {
        int ati = 1 << i; 
        printf("%d ", i + 1);
        for (int node = 0; node < ati; node++) {
            printf("%d ", array[index]);
            index++;
        }
        printf("\n");
    }



    return 0;
}