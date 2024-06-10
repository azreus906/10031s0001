#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    char decimal_string[] = "11";
    char *endptr;
    errno = 0;

    /* 文字列"11"を10進数の数値(11)に変換 */
    long decimal_value = strtol(decimal_string, &endptr, 10);
    if (errno != 0) {
        printf("Conversion Error occured: errno = %d.\n", errno);
        return 0;
    } else if (*endptr != '\0' || decimal_value == LONG_MAX || decimal_value == LONG_MIN) {
        printf("Conversion Error occured: invalid input or overflow/underflow.\n");
        return 0;
    }

    /* 8進数として表示 */
    printf("Octal: %lo\n", decimal_value);
    /* 16進数として表示 */
    printf("Hexadecimal: %lx", decimal_value);
}