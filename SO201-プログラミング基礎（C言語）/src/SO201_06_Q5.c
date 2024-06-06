/*
プログラミング基礎C言語
関数
練習問題5
外部ライブラリの数学関数を使用して、以下を表示してください。
    21の平方根を小数点以下3桁まで

コンパイル方法
================
>>> gcc -Wall -o SO201_06_Q5 SO201_06_Q5.c
================

実行例
================
>>> ./SO201_06_Q5
4.583
================

*/


// ここより下に解答を記載する。
#include <stdio.h>
#include <math.h>

int main() {
    double num = 21;
    printf("%.3f\n", sqrt(num));
}