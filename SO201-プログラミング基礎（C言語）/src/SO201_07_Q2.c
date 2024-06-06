/*
プログラミング基礎C言語
ポインタと構造体
練習問題2
「構造体」のソースコードを変更して、以下の構造体を表示してください。
    Tanaka Ichiro
    25

コンパイル方法
================
>>> gcc -Wall -o SO201_07_Q2 SO201_07_Q2.c
================

実行例
================
>>> ./SO201_07_Q2
user.name = Tanaka Ichiro
user.age = 25
================

*/


// ここより下に解答を記載する。
#include <stdio.h>
#include <string.h>

struct Tuser {
    char name[32];
    int age;
};

int main() {
    struct Tuser user;

    strcpy(user.name, "Tanaka Ichiro");
    user.age = 25;

    printf("user.name = %s\n", user.name);
    printf("user.age = %d\n", user.age);
}



