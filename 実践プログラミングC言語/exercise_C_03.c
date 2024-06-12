#include <stdio.h>

void calc1(int inum, int *pidata, int *pimax, int *pimin, int *piave) {

    int temp_max = 0;
    int temp_min = 0;
    int sum = 0;
    int ave = 0;

    for (int i = 0; i < inum - 1; i++) {
        /* 最大値を求める*/
        if (*(pidata + i) < *(pidata + (i + 1))) {
            temp_max = i + 1;
        }
        /* 最小値を求める */
        if (*(pidata + i ) > *(pidata + (i + 1))) {
            temp_min = i + 1;
        }
    }

    for (int i = 0; i < inum; i++) {
        sum += *(pidata + i); /* 総和を求める */
    }
    ave = sum / inum; /* 平均値を求める*/

    /* 値を代入 */
    *pimax = pidata[temp_max];
    *pimin = pidata[temp_min];
    *piave = ave;
}

int main() {

    int data[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5}; /* 整数型の連続データ */

    int max = 0; /* 最大値 */
    int *pimax = &max; /* 最大値へのポインタ */

    int min = 0; /* 最小値*/
    int *pimin = &min; /* 最小値へのポインタ */
    
    int ave = 0; /* 平均値 */
    int *piave = &ave; /* 平均値へのポインタ */

    /* 配列のデータ数を取得 */
    int inum = sizeof(data) / sizeof(data[0]);

    /* calc1をcallする */
    calc1(inum, data, pimax, pimin, piave);

    /* 計算結果を表示 */
    printf("inum: %d, pimax: %d, pimin: %d, piave: %d", inum, *pimax, *pimin, *piave);
}