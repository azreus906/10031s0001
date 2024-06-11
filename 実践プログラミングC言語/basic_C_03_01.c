#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    char decimal_string[] = "11";
    char *endptr;
    errno = 0;

    /* 文字列"11"を8進数の数値に変換 */
    long oct_value = strtol(decimal_string, &endptr, 8);
    if (errno != 0) {
        printf("Conversion Error occured: errno = %d.\n", errno);
        return 0;
    } else if (*endptr != '\0' || oct_value == LONG_MAX || oct_value == LONG_MIN) {
        printf("Conversion Error occured: invalid input or overflow/underflow.\n");
        return 0;
    }

    /* 文字列"11"を16進数の数値に変換 */
    long hex_value = strtol(decimal_string, &endptr, 16);
    if (errno != 0) {
        printf("Conversion Error occured: errno = %d.\n", errno);
        return 0;
    } else if (*endptr != '\0' || hex_value == LONG_MAX || hex_value == LONG_MIN) {
        printf("Conversion Error occured: invalid input or overflow/underflow.\n");
        return 0;
    }

    /* 8進数として表示 */
    printf("Octal: %ld\n", oct_value);
    /* 16進数として表示 */
    printf("Hexadecimal: %ld", hex_value);
}