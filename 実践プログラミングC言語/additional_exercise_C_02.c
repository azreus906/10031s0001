#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20

struct Person {
    char name[20];
    int age;
    float weight;
    float height;
};

int main(int argc, char *argv[]) {

    char src_filename[] = "src_file.txt"; /* 入力ファイル名 */
    char dest_filename[MAX_FILENAME_LENGTH]; /* 出力ファイル名 */
    FILE *src_fp; /* 入力ファイルのファイル型構造体 */
    FILE *dest_fp; /* 出力ファイルのファイル型構造体 */
    
    /* 引数のチェック */
    if (argc != 2) {
        printf("Error: 引数がありません\n");
        return 0;
    }

    /* 出力ファイル名を読み取る */
    strcpy(dest_filename, argv[1]);

    /* 入力ファイルを開く */
    src_fp = fopen(src_filename, "r");
    if (src_fp == NULL) {
        printf("Error: 入力ファイルを正常に開けませんでした。\n");
        return 0;
    }

    /* 出力ファイルを開く */
    dest_fp = fopen(dest_filename, "w");
    if (dest_fp == NULL) {
        printf("Error: 出力ファイルを正常に開けませんでした。\n");
        fclose(src_fp);
        return 0;
    }

    struct Person person; /* Person型の変数personを初期化 */

    /* 入力ファイルの終端に達するまでループ */
    while (!feof(src_fp)) {

        /* 入力ファイルからデータを読み込む */
        int read_result = fscanf(src_fp, "%s %d %f %f", person.name, &person.age, &person.weight, &person.height);
        
        /* 正常に4つ分データがある場合 */
        if (read_result == 4) {
            /* 読み込んだデータを表示 */
            printf("Name: %s\n", person.name);
            printf("Age = %d\n", person.age);
            printf("Weight = %.1f\n", person.weight);
            printf("Height = %.1f\n", person.height);
            printf("-------------\n");

            /* 読み込んだデータをdest_file.txtに書き込む */
            int write_result = fprintf(dest_fp, "%s %d %.1f %.1f \n", person.name, person.age, person.weight, person.height);

            /* 書き込み処理でエラーが発生した場合 */
            if (write_result < 0) {
                printf("Error: 出力ファイルへの書き込みでエラーが発生しました。\n");
                fclose(src_fp);
                fclose(dest_fp);
                return 0;
            }
            
        } else if (read_result != EOF) {
            /* ファイルフォーマットが正常でない場合のエラー処理 */
            printf("Error: ファイルフォーマットが不正です。\n");
            fclose(src_fp);
            fclose(dest_fp);
            return 0;
        }
    }
    
    fclose(src_fp); /* 入力ファイルを閉じる */
    fclose(dest_fp); /* 出力ファイルを閉じる */

    return 0;
}