#include <stdio.h>

#include "cm_pchk.h"
#include "cm_tbad.h"
#include "cm_efrd.h"
#include "cm_run.h"

int main(int argc, char* argv[]) {

    int o_trls = 0; /* 1:トレースリスト出力しない */
    int *p_o_trls = &o_trls;

    int num_s; /* 最大ステップ数 */
    int *p_num_s = &num_s;

    int mode; /* 0:自動実行モード, 1:マニュアルモード */ 
    int *p_mode = &mode;

    printf("Comet simulator start!\n");

    /* 起動パラメータ解読処理 */
    cm_pchk(argc, argv, p_o_trls, p_num_s, p_mode);

    /* 仮想メモリ取得処理 */
    unsigned short *puhtad;
    *puhtad = cm_tbad();
    printf("puhtad: %p\n", puhtad);

    /* 実行可能ファイル読み込み処理 */
    cm_efrd();

    /* オブジェクトコード実行処理*/
    cm_run();

    return 0;
}