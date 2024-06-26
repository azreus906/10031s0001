/*
プログラミング基礎C言語
ファイル処理
練習問題3
「ファイルを書き出す（追記）」のソースコードを以下に変更してください。
    書き出すファイル名：SO201_08_Q3_output.txt
    書き込む文字列：おはようございます。

コンパイル方法
================
>>> gcc -Wall -o SO201_08_Q3 SO201_08_Q3.c
================

実行例
================
>>> ./SO201_08_Q3
>>> cat SO201_08_Q3_output.txt
こんにちは。
おはようございます。
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("SO201_08_Q3_output.txt", "a");

    fputs("おはようございます。", fp);
    fclose(fp);
}