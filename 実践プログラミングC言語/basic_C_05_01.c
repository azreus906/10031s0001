#include <stdio.h>

int main() {
    int yy, mm, dd;
    char name[20];

    printf(">>input(yymmdd name)? ");
    scanf("%d %d %d %s", &yy, &mm, &dd, name);

    /* 値を表示 */
    printf("yy --> %d\n", yy);
    printf("mm --> %d\n", mm);
    printf("dd --> %d\n", dd);
    printf("name --> %s\n", name);
}