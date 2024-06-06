/*
プログラミング基礎C言語
関数
練習問題2
「ユーザ定義関数」のソースコードを変更して、以下の結果を表示してください。
    7.8 + 3.4

コンパイル方法
================
>>> gcc -Wall -o SO201_06_Q2 SO201_06_Q2.c
================

実行例
================
>>> ./SO201_06_Q2
11.200000
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

double plus(double num1, double num2) {
    double x = num1 + num2;
    return x;
}

int main() {
    double num = plus(7.8, 3.4); //float型だと"11.200001"になる
    printf("%f\n", num);
}
