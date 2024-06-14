#include <stdio.h>
#include <math.h>

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
    
    /* 各項数についての近似値と比較を表示 */
    printf("項数n: \t\t sin(x) \t\t\t マクローリン近似値 \t\t sin(x) - 近似値\n");
    for (int n = 1; n <= N; n++) {
        double sin_val = sin(x);
        double approx_val = maclaurin_sin(x, n);
        double difference = sin_val - approx_val;
        
        printf("%d: \t\t %.15f \t\t %.15f \t\t %.15f \n", n, sin_val, approx_val, difference);
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
