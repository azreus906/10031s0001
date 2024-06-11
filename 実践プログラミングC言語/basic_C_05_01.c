#include <stdio.h>

int main() {
    int yy, mm, dd;
    char name[20];

    /* 入力を受け取る(%02dで2文字区切りにする) */
    printf(">>input(yymmdd name)? ");
    scanf("%02d %02d %02d %s", &yy, &mm, &dd, name);

    /* 値を表示 */
    printf("yy --> %02d\n", yy);
    printf("mm --> %02d\n", mm);
    printf("dd --> %02d\n", dd);
    printf("name --> %s\n", name);
}