#include <stdio.h>

int main() {
    int hex_value = 0x11110;
    int oct_value = 011110;
    char hex_string[20];
    char oct_string[20];
    int iret;

    /* 16進数0x11110を文字列"11110"に変換 */
    iret = sprintf(hex_string, "%x", hex_value);
    if (iret < 0) {
        printf("Error occurred during hexadecimal conversion.");
    }
    printf("hexadecimal: %s\n", hex_string);    
    
    /* 8進数011110を文字列"11110"に変換 */
    iret = sprintf(oct_string, "%o", oct_value);
    if (iret < 0) {
        printf("Error occurred during octal conversion.");
    }
    printf("octal: %s\n", oct_string);

}