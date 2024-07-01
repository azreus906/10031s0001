#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cm_pchk(int argc, char* argv[], int* o_trls, int* num_s, int* mode) {

    printf("---------------------------\n");
    printf("cm_pchk() called\n");
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    /* ここにオプションの値を各ポインタ変数に代入する処理を書く */

    /*
    オプション
    -r : トレースリストを表示しない
    -s : 最大ステップ数指定
    -m : マニュアルモードで命令実行
    */

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-r") == 0) {
            *o_trls = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            *num_s = atoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-m") == 0) {
            *mode = 1;
        }
    }

    printf("o_trls: %d\n", *o_trls);
    printf("num_s: %d\n", *num_s);
    printf("mode: %d\n", *mode);
    printf("---------------------------\n");
}