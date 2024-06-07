/*
プログラミング基礎C言語
プログラミング演習
問題2
コマンドライン引数で指定する範囲の整数を表示してください。
ただし、3の倍数のときは数の代わりに「Fizz」を、5の倍数のときは「Buzz」を出力し、
3と5両方の倍数のときは「FizzBuzz」を出力すること。

コンパイル方法
================
>>> gcc -Wall -o SO201_09_Q2 SO201_09_Q2.c
================

実行例
================
>>> ./SO201_09_Q2
コマンドライン引数が不正です。
================
>>> ./SO201_09_Q2 1
コマンドライン引数が不正です。
================
>>> ./SO201_09_Q2 1 15
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
================

*/


// ここより下に解答を記載する。
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("コマンドライン引数が不正です。");
        return 0;
    }

    /* エラーチェックのためにatoi()よりもstrtolを使った方が良い
    int min = atoi(argv[1]);
    int max = atoi(argv[2]);
    */

    char *endptr;
    errno = 0;

    long min = strtol(argv[1], &endptr, 10);
    if (errno != 0) {
        printf("コマンドライン引数が不正です。");
        return 0;
    } else if (endptr == argv[1]) {
        printf("コマンドライン引数が不正です。");
        return 0;
    }

    long max = strtol(argv[2], &endptr, 10);
    if (errno != 0) {
        printf("コマンドライン引数が不正です。");
        return 0;
    } else if (endptr == argv[2]) {
        printf("コマンドライン引数が不正です。");
        return 0;
    }

    if (min > max) {
        printf("コマンドライン引数が不正です。");
        return 0;
    }

    for (int i = min; i <= max; i++) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else {
            printf("%d\n", i);
        }
    }
}