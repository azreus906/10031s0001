#include <stdio.h>
#include <string.h>

#define MAX_NAME_NUM 8
#define LARGER_PS1 1
#define LARGER_PS2 -1
#define EQUAL_PS1_PS2 0
#define ERROR_VALUE -99

int scmp(char *ps1, char *ps2) {
    
    int len_ps1 = strlen(ps1); /* ps1の文字列の長さを取得 */
    int len_ps2 = strlen(ps2); /* ps2の文字列の長さを取得 */

    /* ps1またはps2が不正な値だった場合はERROR_VALUEでreturnする*/
    if(ps1 == NULL || ps2 == NULL) {
        return ERROR_VALUE;
    } else if(len_ps1 <= 0 || len_ps2 <= 0 || len_ps1 > MAX_NAME_NUM || len_ps2 > MAX_NAME_NUM) {
        return ERROR_VALUE;
    }

    /* ps1とps2の文字の大小比較を行う */
    for(int i = 0; i < MAX_NAME_NUM + 1; i++) { /* +1は終端文字まで比較するため */

        /* s1とs2に文字がまだあるかどうか確認 */
        if(*(ps1 + i) == '\0' && *(ps2 + i) == '\0') {
            return EQUAL_PS1_PS2;
        }else if(*(ps1 + i) == '\0') {
            return LARGER_PS2;
        }else if(*(ps2 + i) == '\0'){
            return LARGER_PS1;
        }else{
            /* 処理なし */
        }

        /* 文字の大小比較 */
        if(*(ps1 + i) < *(ps2 + i)) {
            return LARGER_PS2;
        }else if(*(ps1 + i) > *(ps2 + i)){
            return LARGER_PS1;
        }else{
            /* 処理なし */
        }
    }

    /* for()内で正常にreturnしなかった場合 */
    return ERROR_VALUE;
}

void namesort(char *array[], int num) {

    char *temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < (num - 1) - i; j++) {
            int ret = scmp(array[j], array[j + 1]); /* j番目の要素の先頭アドレスとj+1番目の要素の先頭アドレスを渡す */
            if(ret == LARGER_PS1) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            } else if(ret == ERROR_VALUE) {
                printf("Error: 文字の比較でエラーが発生しました\n");
            } else {
                /* 処理なし */
            }
        }
    }
}

int main() {
    char *name_array[] = {
        "SAZAE___", 
        "WAKAME__",
        "MASUO___",
        "NORISUKE",
        "TARACHAN",
        "KATSUO__",
        "NAMIHEI_"
    };

    int num_names = sizeof(name_array) / sizeof(name_array[0]);

    namesort(name_array, num_names);

    for(int i = 0; i < num_names; i++) {
        printf("%s\n", name_array[i]);
    }

    return 0;
}