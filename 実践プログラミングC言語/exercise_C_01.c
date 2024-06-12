#include <stdio.h>
#include <string.h>

#define MAX_STRING_VALUE 20
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
    } else if(len_ps1 <= 0 || len_ps2 <= 0 || len_ps1 > MAX_STRING_VALUE || len_ps2 > MAX_STRING_VALUE) {
        return ERROR_VALUE;
    }

    /* ps1とps2の文字の大小比較を行う */
    for(int i = 0; i < MAX_STRING_VALUE; i++) {

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

int main() {
    int ret;
    char s1[MAX_STRING_VALUE], s2[MAX_STRING_VALUE];

    /* 値の入力を受け付ける */
    printf("s1の値を入力してください(最大19文字): ");
    scanf("%s", s1);
    printf("s2の値を入力してください(最大19文字): ");
    scanf("%s", s2);

    /* scmpをcallする */
    ret = scmp(s1, s2);
    printf("ret: %d", ret);
}