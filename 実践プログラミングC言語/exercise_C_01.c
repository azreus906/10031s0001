#include <stdio.h>

#define MAX_STRING_VALUE 20
#define LARGER_PS1 1
#define LARGER_PS2 -1
#define EQUAL_PS1_PS2 0
#define ERROR_VALUE -99

int scmp(char *ps1, char *ps2) {

    for(int i = 0; i < MAX_STRING_VALUE; i++) {
        /* s1とs2に文字がまだあるかどうか確認 */
        if(*(ps1 + i) == '\0' && *(ps2 + i) == '\0') {
            return EQUAL_PS1_PS2;
        }else if(*(ps1 + i) == '\0') {
            return LARGER_PS2;
        }else if(*(ps2 + i) == '\0'){
            return LARGER_PS1;
        }else{
            continue;
        }

        /* 文字の大小比較 */
        if(*(ps1 + i) < *(ps2 + i)) {
            return LARGER_PS2;
        }else if(*(ps1 + i) > *(ps2 + i)){
            return LARGER_PS1;
        }else{
            continue;
        }
    }

    /* for()内で正常にreturnしなかった場合*/
    return ERROR_VALUE;
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