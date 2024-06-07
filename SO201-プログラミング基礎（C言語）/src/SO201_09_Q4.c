/*
プログラミング基礎C言語
プログラミング演習
問題4
コマンドライン引数で入力された英数字を逆順に並べ替えて表示してください。

コンパイル方法
================
>>> gcc -Wall -o SO201_09_Q4 SO201_09_Q4.c
================

実行例
================
>>> ./SO201_09_Q4
コマンドライン引数が不正です。
================
>>> ./SO201_09_Q4 abcdef
fedcba
================
>>> ./SO201_09_Q4 1234567890
0987654321
================

*/


// ここより下に解答を記載する。
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 2){
        printf("コマンドライン引数が不正です。\n");
        return 0;
    }

    char *str = argv[1];
    int length = strlen(str);

    for (int i = (length-1); str[i] != '\0'; i--) {
        printf("%c", str[i]);
    }
}