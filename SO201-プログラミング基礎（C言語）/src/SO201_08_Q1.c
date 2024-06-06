/*
プログラミング基礎C言語
ファイル処理
練習問題1
「ファイルを読み込む」のソースコードを以下に変更してください。
    読み込むファイル名：SO201_08_Q1_input.txt

コンパイル方法
================
>>> gcc -Wall -o SO201_08_Q1 SO201_08_Q1.c
================

実行例
================
>>> ./SO201_08_Q1
これは、
読み込み用のファイル
です。
================

*/


// ここより下に解答を記載する。

#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("SO201_08_Q1_input.txt", "r");
    char buffer[256];

    while(1) {
        fgets(buffer, 256, fp);
        if (feof(fp)) {
            break;
        }
        printf("%s", buffer);
    }
    fclose(fp);
}
