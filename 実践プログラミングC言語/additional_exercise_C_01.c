#include <stdio.h>
#include <math.h>

#define MIN_N_VALUE 0
#define MAX_N_VALUE 50
#define MIN_X_VALUE 0
#define MAX_X_VALUE 50

double maclaurin_sin(double x, int n); /* マクローリン展開を使用してsin(x)を計算する関数 */
double factorial(int n); /* 階乗を計算する関数 */

int main() {
    double x;
    int N;
    
    /* ユーザーからの入力を受け取る */
    printf("input x > ");
    scanf("%lf", &x);
    printf("input N > ");
    scanf("%d", &N);

    /* xとNの値のチェック */
    if (x < MIN_X_VALUE || x > MAX_X_VALUE) {
        printf("Error: xの値が範囲外です\n");
        return 0;
    } else if (N < MIN_N_VALUE || N > MAX_N_VALUE) {
        printf("Error: Nの値が範囲外です\n");
        return 0;
    }
    
    /* 各項数についての近似値と比較を表示 */
    printf("項数n: \t\t sin(x) \t\t マクローリン近似値 \t\t sin(x) - 近似値 \n");
    for (int n = 1; n <= N; n++) {
        double sin_val = sin(x);
        double approx_val = maclaurin_sin(x, n);
        double difference = sin_val - approx_val;
        
        printf("%d: \t\t %-10.5f \t\t %-10.5f \t\t %-10.5f \n", n, sin_val, approx_val, difference);
    }
    
    return 0;
}

double maclaurin_sin(double x, int n) {
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        sum += term;
    }
    
    return sum;
}

double factorial(int n) {
    double result = 1.0;
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}
