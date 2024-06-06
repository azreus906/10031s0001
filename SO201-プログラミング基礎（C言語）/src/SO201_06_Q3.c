/*
プログラミング基礎C言語
関数
練習問題3
練習問題2に、「引き算した結果を返す関数」を追加して、以下の結果を表示してください。
    7.8 - 3.4

コンパイル方法
================
>>> gcc -Wall -o SO201_06_Q3 SO201_06_Q3.c
================

実行例
================
>>> ./SO201_06_Q3
4.400000
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

double plus(double num1, double num2) {
    double x = num1 + num2;
    return x;
}

double minus(double num1, double num2) {
    double x = num1 - num2;
    return x;
}

int main() {
    double num = minus(7.8, 3.4);
    printf("%f\n", num);
}
