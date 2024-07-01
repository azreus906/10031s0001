#include <stdio.h>

#include "cm_command.h"

void cm_run() {
    printf("---------------------------\n");
    printf("cm_run() called\n");

    /* ここにオブジェクトコード実行処理を書く */
    cm_ld();
    cm_st();
    cm_adda();
    cm_sll();
    cm_exit();
    cm_trls();
    cm_erhd();
}