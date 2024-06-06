/*
プログラミング基礎C言語
演算子
練習問題2
a = 6、b = 7のとき、以下の演算結果を表示してください。
    aとbの論理積
    aとbの排他的論理和
    aのビットの反転
    aを3ビット左シフト

コンパイル方法
================
>>> gcc -Wall -o SO201_04_Q2 SO201_04_Q2.c
================

実行例
================
>>> ./SO201_04_Q2
6
1
-7
48
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    int a = 6;
    int b = 7;
    printf("%d\n", a & b);
    printf("%d\n", a ^ b);
    printf("%d\n", ~ a);
    printf("%d\n", a << 3);
}