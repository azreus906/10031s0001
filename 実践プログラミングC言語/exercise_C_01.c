#include <stdio.h>
#define MAX_STRING_VALUE 20

int scmp(char *ps1, char *ps2) {
    /* retをエラー値で初期化*/
    int ret = -99;

    for(int i = 0; i < MAX_STRING_VALUE; i++) {
        /* s1とs2に文字がまだあるかどうか確認 */
        if(*(ps1 + i) == '\0' && *(ps2 + i) == '\0') {
            ret = 0;
            return ret;
        }else if(*(ps1 + i) == '\0') {
            ret = -1;
            return ret;
        }else if(*(ps2 + i) == '\0'){
            ret = 1;
            return ret;
        }

        /* 文字の大小比較 */
        if(*(ps1 + i) < *(ps2 + i)) {
            ret = -1;
            return ret;
        }else if(*(ps1 + i) > *(ps2 + i)){
            ret = 1;
            return ret;
        }else{
            ret = 0;
        }
    }
    return ret;
}

int main() {
    int ret;
    char s1[MAX_STRING_VALUE], s2[MAX_STRING_VALUE];

    /* 値の入力を受け付ける */
    printf("s1の値を入力してください: ");
    scanf("%s", s1);
    printf("s2の値を入力してください: ");
    scanf("%s", s2);

    /* scmpをcallする */
    ret = scmp(s1, s2);
    printf("ret: %d", ret);
}