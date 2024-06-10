#include <stdio.h>
#include <string.h>

int main() {

    char birth[20];
    char name[20];
    char yy[3], mm[3], dd[3];

    /* 入力を受け取る */
    printf(">>input(yymmdd name)? ");
    scanf("%s %s", birth, name);

    /* yy, mm, ddに値を代入*/
    strncpy(yy, birth, 2);
    yy[2] = '\0';
    strncpy(mm, birth + 2, 2);
    mm[2] = '\0';
    strncpy(dd, birth + 4, 2);
    dd[2] = '\0';

    /* 値を表示 */
    printf("yy --> %s\n", yy);
    printf("mm --> %s\n", mm);
    printf("dd --> %s\n", dd);
    printf("name --> %s\n", name);
}




