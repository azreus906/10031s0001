#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define CORRECT_VALUE 1
#define ERROR_VALUE -1

int insertRecord(char *); /* レコードの挿入と並び替えを行う関数 */
int searchRecord(char *); /* レコードの検索を行う関数 */
int displayRecord(char *); /* レコードの表示を行う関数 */

struct Person {
    char name[20];
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
        scanf("%c", &command);

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
                break;
            default:
                printf("Error: コマンドの値が不正です。\n");
        }

    }

    return 0;
}

int insertRecord(char *filename) {

    FILE *fp;

    /* ファイルを開く */
    fp = fopen(filename, "a");
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

    /* 新規レコードをファイルに書き込む */
    int write_result = fprintf(fp, "\n %s %d %.1f %.1f", new_person.name, new_person.age, new_person.weight, new_person.height);

    /* 書き込み処理でエラーが発生した場合 */
    if (write_result < 0) {
        printf("Error: 出力ファイルへの書き込みでエラーが発生しました。\n");
        fclose(fp);
        return ERROR_VALUE;
    }

    return CORRECT_VALUE;
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