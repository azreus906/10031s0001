/*
プログラミング基礎C言語
制御構文
練習問題1
「if文」のソースコードを以下に変更してください。
    num = 30

コンパイル方法
================
>>> gcc -Wall -o SO201_05_Q1 SO201_05_Q1.c
================

実行例
================
>>> ./SO201_05_Q1
numは、50未満の数字です。
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    int num = 30;

    if (num < 50) {
        printf("numは、50未満の数字です。");
    } else if (num < 80) {
        printf("numは、50以上80未満の数字です。");
    } else {
        printf("numは、80以上の数字です。");
    }
}
