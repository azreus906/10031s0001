/*
プログラミング基礎C言語
変数とデータ型
練習問題3
以下の配列を宣言して、0番目の要素を表示してください。
    1
    2
    3
    4

コンパイル方法
================
>>> gcc -Wall -o SO201_03_Q3 SO201_03_Q3.c
================

実行例
================
>>> ./SO201_03_Q3
1
================

*/


// ここより下に解答を記載する。
int main() {
    int a[] = {1, 2, 3, 4};
    printf("%d", a[0]);
}