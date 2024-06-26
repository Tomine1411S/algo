#include<stdio.h>

void move (int no, int x, int y ) {
    if (no > 1) {
        move (no - 1, x, 6 - x - y);
    }
    printf("No.[ %2d ] is moved from pos#[ %d ] to pos#[ %d ]\n", no, x, y);
    if (no > 1) {
        move(no - 1, 6 - x - y, y);
    }
}




int main(void) {
    int count;
    printf("Tower_of_Hanoi\ncount? :");
    scanf("%d", &count);
    move(count, 1, 3);

    return 0;
}