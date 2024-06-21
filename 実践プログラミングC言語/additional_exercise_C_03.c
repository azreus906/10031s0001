#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define CORRECT_VALUE 1
#define ERROR_VALUE -1
#define LARGER_PS1 1
#define LARGER_PS2 -1
#define EQUAL_PS1_PS2 0

#define MIN_NAME_LENGTH 1
#define MAX_NAME_LENGTH 20
#define MIN_AGE_VALUE 0
#define MAX_AGE_VALUE 100
#define MIN_WEIGHT_VALUE 1
#define MAX_WEIGHT_VALUE 200
#define MIN_HEIGHT_VALUE 1
#define MAX_HEIGHT_VALUE 200

int insertRecord(char *); /* レコードの挿入と並び替えを行う関数 */
int scmp(char *, char *); /* 文字列の順序比較を行う関数 */
int searchRecord(char *); /* レコードの検索を行う関数 */
int displayRecord(char *); /* レコードの表示を行う関数 */

struct Person {
    char name[MAX_FILENAME_LENGTH];
    int age;
    float weight;
    float height;
};

int main(int argc, char *argv[]) {

    /* 引数の数を確認 */
    if (argc < 2) {
        printf("引数がありません。\n");
        return 0;
    }

    /* ファイル名を読み取る */
    char filename[MAX_FILENAME_LENGTH];
    strcpy(filename, argv[1]);

    char command = 'o'; /* デフォルト値で初期化 */

    while(command != 'e'){

        int ret; /* 各関数からの戻り値 */

        printf("\n============================================= \n");
        printf("Input command \n");
        printf(" i(:insert) s(:search) d(:display) e(:end) \n");
            

        switch (command) {
            case 'i':
                ret = insertRecord(filename);
                if (ret == CORRECT_VALUE) {
                    printf("レコードの挿入処理が正常に完了しました。\n");
                } else if (ret == ERROR_VALUE) {
                    printf("Error: レコードの挿入処理でエラーが発生しました。\n");
                } else {
                    printf("Error: レコードの挿入処理で不正な値がreturnされました。\n");
                }
                break;
            case 's':
                ret = searchRecord(filename);
                if (ret == CORRECT_VALUE) {
                    printf("レコードの検索処理が正常に完了しました。\n");
                } else if (ret == ERROR_VALUE) {
                    printf("Error: レコードの検索処理でエラーが発生しました。\n");
                } else {
                    printf("Error: レコードの検索処理で不正な値がreturnされました。\n");
                }
                break;
            case 'd':
                ret = displayRecord(filename);
                if (ret == CORRECT_VALUE) {
                    printf("レコードの表示処理が正常に完了しました。\n");
                } else if (ret == ERROR_VALUE) {
                    printf("Error: レコードの表示処理でエラーが発生しました。\n");
                } else {
                    printf("Error: レコードの表示処理で不正な値がreturnされました。\n");
                }
                break;
            case 'e':
                printf("プログラムを終了します。\n");
                return 0;
            default:
                printf("Error: コマンドの値が不正です。\n");
                break;
        }
    }
}

int insertRecord(char *filename) {

    FILE *fp;

    /* ファイルを開く */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: ファイルを正常に開けませんでした。\n");
        return ERROR_VALUE;
    }

    /* 新しいレコードの値を受け付ける */
    struct Person new_person;
    printf("Enter name: ");
    scanf("%s", new_person.name);
    printf("Enter age: ");
    scanf("%d", &new_person.age);
    printf("Enter weight: ");
    scanf("%f", &new_person.weight);
    printf("Enter height: ");
    scanf("%f", &new_person.height);

    /* new_person.nameのチェック */
    if (strlen(new_person.name) < MIN_NAME_LENGTH || strlen(new_person.name) > MAX_NAME_LENGTH) {
        printf("Error: 新規レコードの名称(name)が不正です。\n");
        return ERROR_VALUE;
    }
    /* new_person.ageのチェック */
    if (new_person.age < MIN_AGE_VALUE || new_person.age > MAX_AGE_VALUE) {
        printf("Error: 新規レコードの年齢(age)の値が不正です。\n");
        return ERROR_VALUE;
    }
    /* new_person.weightのチェック */
    if (new_person.age < MIN_WEIGHT_VALUE || new_person.age > MAX_WEIGHT_VALUE) {
        printf("Error: 新規レコードの体重(weight)の値が不正です。\n");
        return ERROR_VALUE;
    }
    /* new_person.heightのチェック */
    if (new_person.age < MIN_HEIGHT_VALUE || new_person.age > MAX_HEIGHT_VALUE) {
        printf("Error: 新規レコードの身長(height)の値が不正です。\n");
        return ERROR_VALUE;
    }

    struct Person person;
    FILE *tmp_fp = fopen("tmp.txt", "w"); /* tmpファイルtmp.txtを作成する */
    int incerted = 0; /* 新規レコードが挿入済みかどうかを判断するフラグ */
    
    while(!feof(fp)) {

         /* 入力ファイルからデータを読み込む */
        fscanf(fp, "%s %d %f %f", person.name, &person.age, &person.weight, &person.height);
        
        /* 名前を比較する */
        int ret = scmp(new_person.name, person.name);

        if (incerted == 1) { /* 既に挿入済みの場合は既存のレコードを登録する */
            fprintf(tmp_fp, "%s %d %.1f %.1f \n", person.name, person.age, person.weight, person.height);
        } else if (ret == LARGER_PS1) { /* 既存の名前の方が辞書順で前の場合 */
            fprintf(tmp_fp, "%s %d %.1f %.1f \n", person.name, person.age, person.weight, person.height);
        } else if (ret == LARGER_PS2) { /* 新規の名前の方が辞書順で前の場合 */
            fprintf(tmp_fp, "%s %d %.1f %.1f \n", new_person.name, new_person.age, new_person.weight, new_person.height);
            fprintf(tmp_fp, "%s %d %.1f %.1f \n", person.name, person.age, person.weight, person.height);
            incerted = 1; /* 挿入済みフラグを1にする */
        } else {
            printf("Error: scmp()の処理でErrorが発生しました。ret: %d \n", ret);
        }
    }

    /* 最後までレコードが挿入されなかった場合はファイルの最後尾に追加する */
    if (incerted == 0) {
        fprintf(tmp_fp, "%s %d %.1f %.1f", new_person.name, new_person.age, new_person.weight, new_person.height);
    }

    fclose(fp);
    fclose(tmp_fp);

    /* オリジナルのファイルを削除し，tmp.txtの名称を変更する */
    remove(filename);
    rename("tmp.txt", filename);

    return CORRECT_VALUE;
}

int scmp(char *ps1, char *ps2) {

    int len_ps1 = strlen(ps1); /* ps1の文字列の長さを取得 */
    int len_ps2 = strlen(ps2); /* ps2の文字列の長さを取得 */

    /* ps1またはps2が不正な値だった場合はERROR_VALUEでreturnする*/
    if(ps1 == NULL || ps2 == NULL) {
        return ERROR_VALUE;
    } else if(len_ps1 <= 0 || len_ps2 <= 0 || len_ps1 > MAX_NAME_LENGTH || len_ps2 > MAX_NAME_LENGTH) {
        return ERROR_VALUE;
    }

    /* ps1とps2の文字の大小比較を行う */
    for(int i = 0; i < MAX_NAME_LENGTH; i++) {

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

int searchRecord(char *filename) {
    
    FILE *fp;

    /* ファイルを開く */
    fp = fopen(filename, "r+b");
    if (fp == NULL) {
        printf("Error: ファイルを正常に開けませんでした。\n");
        return ERROR_VALUE;
    }

    /* 対象の名前を受け付ける */
    char searchName[20];
    printf("Name = ");
    scanf("%s", searchName);

    struct Person person; /* Person型の変数personを初期化 */

    /* 入力ファイルの終端に達するまでループ */
    while (!feof(fp)) {

         /* 入力ファイルからデータを読み込む */
        int read_result = fscanf(fp, "%s %d %f %f", person.name, &person.age, &person.weight, &person.height);

        if (read_result == 4) {
            if (strcmp(person.name, searchName) == 0) { /* 名前が一致した場合 */
                printf("対象者が見つかりました。\n");
                printf("-------------\n");
                printf("Name: %s\n", person.name);
                printf("Age = %d\n", person.age);
                printf("Weight = %.1f\n", person.weight);
                printf("Height = %.1f\n", person.height);
                printf("-------------\n");
                fclose(fp);
                return CORRECT_VALUE;
            }
        } else if (read_result != EOF) {
            /* ファイルフォーマットが正常でない場合のエラー処理 */
            printf("Error: ファイルフォーマットが不正です。\n");
            fclose(fp);
            return ERROR_VALUE;
        }
    }

    printf("対象者が見つかりませんでした。\n");
    fclose(fp);

    return CORRECT_VALUE;
}

int displayRecord(char *filename) {

    FILE *fp;

    /* ファイルを開く */
    fp = fopen(filename, "r+b");
    if (fp == NULL) {
        printf("Error: ファイルを正常に開けませんでした。\n");
        return ERROR_VALUE;
    }

    struct Person person; /* Person型の変数personを初期化 */

    /* ファイルの終端に達するまでループ */
    while (!feof(fp)) {

        /* ファイルからデータを読み込む */
        int read_result = fscanf(fp, "%s %d %f %f", person.name, &person.age, &person.weight, &person.height);
        
        /* 正常に4つ分データがある場合 */
        if (read_result == 4) {
            /* 読み込んだデータを表示 */
            printf("-------------\n");
            printf("Name: %s\n", person.name);
            printf("Age = %d\n", person.age);
            printf("Weight = %.1f\n", person.weight);
            printf("Height = %.1f\n", person.height);
            printf("-------------\n");
        } else if (read_result != EOF) {
            /* ファイルフォーマットが正常でない場合のエラー処理 */
            printf("Error: ファイルフォーマットが不正です。\n");
            fclose(fp);
            return ERROR_VALUE;
        }
    }
    
    fclose(fp); /* ファイルを閉じる */

    return CORRECT_VALUE;
}