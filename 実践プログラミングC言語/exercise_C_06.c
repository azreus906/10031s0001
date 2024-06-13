#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MIN_YEAR_VALUE 1
#define MAX_YEAR_VALUE 9999
#define MIN_NISSU_VALUE 1
#define MAX_NISSU_NON_LEAP_VALUE 365
#define MAX_NISSU_LEAP_VALUE 366
#define MAX_MONTH_VALUE 12
#define ERROR_VALUE -1

int convert_string_to_int(char *, char); /* 文字列を数値に変換する関数 */
void calc_month_and_day(int, int, int *, int *); /* 通算日数から月と日を計算する関数 */

int main(int argc, char *argv[]) {

    int year = 0;
    int nissu = 0;
    int month = 1;
    int *pm = &month; /* monthの値のアドレス */
    int day = 1;
    int *pd = &day; /* dayの値のアドレス */

    /* 引数が年，通算日数の2つあるか確認 */
    for (int i = 1; i <= 2; i++) {
        if (argv[i] == NULL) {
            printf("Error: 引数がありません\n");
            return ERROR_VALUE;
        }
    }

    /* yearを文字列から数値に変換 */
    year = convert_string_to_int(argv[1], 'y');
    if (year == ERROR_VALUE) {
        return ERROR_VALUE;
    }

    /* nissuを文字列から数値に変換 */
    if (year % 4 == 0) {
        nissu = convert_string_to_int(argv[2], 'l'); /* 閏年の場合 */
    } else {
        nissu = convert_string_to_int(argv[2], 'n'); /* 平年の場合 */
    }
    if (nissu == ERROR_VALUE) {
        return ERROR_VALUE;
    }

    /* 値を表示 */
    printf("year = %d\n", year);
    printf("nissu = %d\n", nissu);

    /* 月と日を計算 */
    calc_month_and_day(year, nissu, pm, pd);
    printf("month = %d\n", *pm);
    printf("day = %d\n", *pd);

    return 0;
}

int convert_string_to_int(char string[], char type) {
    
    char *endp;
    errno = 0;

    /* stringをintに変換 */
    int value = strtol(string, &endp, 10);
    if (errno != 0) {
        printf("Error: コマンドライン引数が不正です\n");
        return ERROR_VALUE;
    } else if (endp == string) {
        printf("Error: コマンドライン引数が不正です\n");
        return ERROR_VALUE;
    }

    /* 値のチェック */
    if (type == 'y') {
        if (value < MIN_YEAR_VALUE || value > MAX_YEAR_VALUE) {
            printf("Error: yearの入力値が不正です\n");
            return ERROR_VALUE;
        }
    } else if (type == 'l') {
        if (value < MIN_NISSU_VALUE || value > MAX_NISSU_LEAP_VALUE) {
            printf("Error: nissuの入力値が不正です\n");
            return ERROR_VALUE;
        }
    } else if (type == 'n') {
        if (value < MIN_NISSU_VALUE || value > MAX_NISSU_NON_LEAP_VALUE) {
            printf("Error: nissuの入力値が不正です\n");
            return ERROR_VALUE;
        }
    } else {
        printf("Error: typeの値が不正です\n");
        return ERROR_VALUE;
    }

    return value;
}

void calc_month_and_day(int year, int nissu, int *pm, int *pd) {

    int leap_year = 0; /* 閏年であれば1*/

    /* 閏年かどうかを判定 */
    if (year % 4 == 0) {
        leap_year = 1;
    }

    /* 今は何月何日かを求める */
    for (int i = 1; i <= MAX_MONTH_VALUE; i++) {
        /* 31日ある月について */
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10) {
            if (nissu > 31) {
                nissu -= 31;
                *pm += 1;
            } else {
                *pd = nissu;
                break;
            }
        /* 30日ある月について */
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
             if (nissu > 30) {
                nissu -= 30;
                *pm += 1;
             } else {
                *pd = nissu;
                break;
             }
        /* 2月(平年)について */
        } else if (i == 2 && leap_year == 0) {
            if (nissu > 28) {
                nissu -= 28;
                *pm += 1;
            } else {
                *pd = nissu;
                break;
            }
        /* 2月(閏年)について */
        } else if (i == 2 && leap_year == 1) {
            if (nissu > 29) {
                nissu -= 29;
                *pm += 1;
            } else {
                *pd = nissu;
                break;
            }
        /* 12月について */
        } else if (i == 12) {
            *pd = nissu;
            break;
        } else {
            /* 処理なし */
        }
    }
}