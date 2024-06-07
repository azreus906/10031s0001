/*
プログラミング基礎C言語
プログラミング演習
問題3
以下の配列を小さい順に並び替えて表示してください。
    2, 13, 99, 20, 28, 64, 33, 73, 20, 1, 73

コンパイル方法
================
>>> gcc -Wall -o SO201_09_Q3 SO201_09_Q3.c
================

実行例
================
>>> ./SO201_09_Q3
1, 2, 13, 20, 20, 28, 33, 64, 73, 73, 99
================

*/


// ここより下に解答を記載する。
#include <stdio.h>

int main() {
    int array[] = {2, 13, 99, 20, 28, 64, 33, 73, 20, 1, 73};
    int size = sizeof(array)/sizeof(array[0]);
    int temp = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[j + 1] < array[j]) {
                temp =  array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if(i < size - 1) {
            printf(", ");
        }
    }
}
