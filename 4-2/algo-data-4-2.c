#include <stdio.h>
#include <stdlib.h>


// 再起関数
int Rec(int num, int *array, int *count) {
    if (num == 0) {
        return 0; // 再帰を終了する. 
    } else { 
        (*count)++;
        return array[num - 1] + Rec(num-1, array, count); // 再帰なので引数は-1している
    }
}

int main(void) {
    int num;
    scanf("%d", &num); 

    if (num >= 10000) {
        printf("Error"); 
        return 10; 
    }

    int array[10000];
    for (int i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }

    int count = 0; 
    int ans = Rec(num, array, &count);

    printf("%d\n", ans); // 和
    printf("%d\n", count -1); // 和の計算の実行回数

}