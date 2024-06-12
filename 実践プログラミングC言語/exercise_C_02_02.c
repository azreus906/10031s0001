#include <stdio.h>
#include <string.h>

#define NAME_DATA_SIZE 16
#define MAX_DATA_NUM 10
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
    } else if(len_ps1 <= 0 || len_ps2 <= 0 || len_ps1 > NAME_DATA_SIZE || len_ps2 > NAME_DATA_SIZE) {
        return ERROR_VALUE;
    }

    /* ps1とps2の文字の大小比較を行う */
    for(int i = 0; i < NAME_DATA_SIZE + 1; i++) { /* +1は終端文字まで比較するため */

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
    FILE *fp;
    char file_name[] = "namefile"; /* 読み込むファイル名 */
    char buffer[MAX_DATA_NUM][NAME_DATA_SIZE]; /* fread()で読み込んだ値を格納する2次元配列 */
    char *name_array[MAX_DATA_NUM]; /* 名前を格納するポインタ配列 */
    int data_unit = 1; /* char型は1文字1byteのため */
    int data_count = 0; /* 有効データ数 */

    /* ファイルを開く */
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: ファイルを開けませんでした\n");
        return 0;
    }

    /* ファイルからデータを読み込む */
    while (fread(buffer[data_count], data_unit, NAME_DATA_SIZE, fp) == NAME_DATA_SIZE) {

        /* ファイルの1文字目が空白だったら終了 */
        if (data_count == 0 && buffer[data_count][0] == ' ') {
            printf("Error: ファイルにデータがありません\n");
            break;
        }
        
        /* データの先頭が空白だったら終了 */
        if (buffer[data_count][0] == ' ') {
            break; 
        }

        /* bufferの値をname_arrayに入れる */
        name_array[data_count] = buffer[data_count];
        data_count++;

        /* 最大データ個数を超えた場合は終了*/
        if (data_count >= MAX_DATA_NUM) {
            break;
        }
    }

    /* 読み込み中にエラーが発生していないか確認 */
    if (ferror(fp)) {
        printf("Error: ファイル読み込み中にエラーが発生しました\n");
        fclose(fp);
        return 0;
    }

    /* ファイルを閉じる */
    if (fclose(fp) != 0) {
        printf("Error: ファイルを正常に閉じることができませんでした\n");
        return 0;
    }

    /* 読み込んだデータを表示 */
    printf("[並び替え前] \n");
    for (int i = 0; i < data_count; i++) {
        printf("%s\n", name_array[i]);
    }

    /* ソートを行う */
    namesort(name_array, data_count);

    /* ソートしたデータを表示 */
    printf("-----------------------\n");
    printf("[並び替え後] \n");
    for (int i = 0; i < data_count; i++) {
        printf("%s\n", name_array[i]);
    }

    return 0;
}
