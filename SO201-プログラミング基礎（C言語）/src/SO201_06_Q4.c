/*
プログラミング基礎C言語
関数
練習問題4
外部ライブラリの数学関数を使用して、以下を表示してください。
    -2.4の絶対値

コンパイル方法
================
>>> gcc -Wall -o SO201_06_Q4 SO201_06_Q4.c
================

実行例
================
>>> ./SO201_06_Q4
2.400000
================

*/


// ここより下に解答を記載する。
#include <stdio.h>
#include <math.h>

int main() {
    float num = -2.4;
    printf("%f\n", fabs(num));
}