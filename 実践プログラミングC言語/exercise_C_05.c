#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MIN_YEAR_VALUE 1
#define MAX_YEAR_VALUE 9999
#define MIN_MONTH_VALUE 1
#define MAX_MONTH_VALUE 12
#define MIN_DAY_VALUE 1
#define MAX_DAY_VALUE 31
#define ERROR_VALUE -1

int convert_string_to_int(char *, char); /* 文字列を数値に変換する関数 */
int calc_total_day(int, int, int); /* 通算日数を計算する関数 */

int main(int argc, char *argv[]) {

    int year = 0;
    int month = 0;
    int day = 0;

    /* 引数が年,月,日の3つあるか確認 */
    if (argc != 4) {
        printf("Error: 引数がありません\n");
        return ERROR_VALUE;
    }

    /* yearを文字列から数値に変換 */
    year = convert_string_to_int(argv[1], 'y');
    if (year == ERROR_VALUE) {
        return ERROR_VALUE;
    }

    /* monthを文字列から数値に変換 */
    month = convert_string_to_int(argv[2], 'm');
    if (month == ERROR_VALUE) {
        return ERROR_VALUE;
    }

    /* dayを文字列から数値に変換 */
    day = convert_string_to_int(argv[3], 'd');
    if (day == ERROR_VALUE) {
        return ERROR_VALUE;
    }

    /* 値を表示 */
    printf("year = %d\n", year);
    printf("month = %d\n", month);
    printf("day = %d\n", day);

    /* 通算日数を計算 */
    int nissu = calc_total_day(year, month, day);
    printf("nissu = %d\n", nissu);

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
    } else if (type == 'm') {
        if (value < MIN_MONTH_VALUE || value > MAX_MONTH_VALUE) {
            printf("Error: monthの入力値が不正です\n");
            return ERROR_VALUE;
        }
    } else if (type == 'd') {
        if (value < MIN_DAY_VALUE || value > MAX_DAY_VALUE) {
            printf("Error: dayの入力値が不正です\n");
            return ERROR_VALUE;
        }
    } else {
        printf("Error: typeの値が不正です\n");
        return ERROR_VALUE;
    }

    return value;
}

int calc_total_day(int year, int month, int day) {

    const int days[] = {28, 29, 30, 31};

    int leap_year = 0; /* 閏年であれば1 */
    int total_day = 0; /* 通算日数 */

    /* 閏年かどうかを判定 */
    if (year % 4 == 0) {
        leap_year = 1;
    }
    
    /* 前の月までの日数を加算 */
    for (int i = 1; i < month; i++) {  
        if (i == 1) {
            total_day += days[3];
        } else if (i == 2 && leap_year == 0) {
            total_day += days[0];
        } else if (i == 2 && leap_year == 1) {
            total_day += days[1];
        } else if (i == 3) {
            total_day += days[3];
        } else if (i == 4) {
            total_day += days[2];
        } else if (i == 5) {
            total_day += days[3];
        } else if (i == 6) {
            total_day += days[2];
        } else if (i == 7) {
            total_day += days[3];
        } else if (i == 8) {
            total_day += days[3];
        } else if (i == 9) {
            total_day += days[2];
        } else if (i == 10) {
            total_day += days[2];
        } else if (i == 11) {
            total_day += days[3];
        }else{
            printf("Error: 通算日の計算でエラーが発生しました\n");
            return ERROR_VALUE;
        }
    }

    /* 今月の今日までの日数を加算 */
    total_day += day;

    return total_day;
}
