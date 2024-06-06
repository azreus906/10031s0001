/*
プログラミング基礎C言語
制御構文
練習問題2
「switch文」のソースコードを以下に変更してください。
    num = 8

コンパイル方法
================
>>> gcc -Wall -o SO201_05_Q2 SO201_05_Q2.c
================

実行例
================
>>> ./SO201_05_Q2
numを3で割った余りは、2です。
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    int num = 8;
    switch (num % 3) {
        case 0:
            printf("numを3を割った余りは、0です。");
            break;
        case 1:
            printf("numを3で割った余りは、1です。");
            break;
        case 2:
            printf("numを3で割った余りは、2です。");
            break;
        default:
            printf("numに誤りがあります。");
            break;
    }
}
