/*
プログラミング基礎C言語
変数とデータ型
練習問題2
以下の文字列を変数に代入して表示してください。
    He said "Hello World!!".

コンパイル方法
================
>>> gcc -Wall -o SO201_03_Q2 SO201_03_Q2.c
================

実行例
================
>>> ./SO201_03_Q2
He said "Hello World!!".
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    char s[] = "He said \"Hello World!!\".";
    printf("%s", s);
}
