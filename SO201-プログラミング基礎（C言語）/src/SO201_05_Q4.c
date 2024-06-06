/*
プログラミング基礎C言語
制御構文
練習問題4
「while文」のソースコードを以下に変更してください。
    num = 15

コンパイル方法
================
>>> gcc -Wall -o SO201_05_Q4 SO201_05_Q4.c
================

実行例
================
>>> ./SO201_05_Q4
15
16
17
18
19
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    int num = 15;
    while (num < 20) {
        printf("%d\n", num);
        num += 1;
    }
}