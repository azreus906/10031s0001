#include <stdio.h>

struct  city{
    char name[20];
    int area;
    float population;
};

float calc_density(struct city *city) {
    float density = city->population * 10000 / city->area;
    printf("%sの人口密度: %.2f [人/km2]\n", city->name, density);
    return density;
}

int add_area(int sum, struct city *city) {
    sum += city->area;
    return sum;
}

float add_population(float sum, struct city *city) {
    sum += city->population;
    return sum;
}

int main() {
    struct city cities[] = {
        {"SAPPORO", 1118, 140.2},
        {"SENDAI", 237, 66.5},
        {"TOKYO", 596, 835.2},
        {"NAGOYA", 328, 208.8},
        {"OSAKA", 212, 264.8},
        {"HIROSHIMA", 676, 89.9},
        {"FUKUOKA", 336, 108.9}
    };
    
    /* 都市の数を求める */
    int num_city = sizeof(cities) / sizeof(cities[0]);

    int sum_area = 0;
    float density = 0;
    float sum_density = 0;
    float sum_population = 0;
    float ave_density = 0;
    
    for(int i = 0; i < num_city; i++) {

        /* 各都市の人口密度を求める */
        density = calc_density(&cities[i]);
        
        /* 人口密度の和を求める */
        sum_density += density;

        /* 面積の総和を求める */
        sum_area += add_area(sum_area, &cities[i]);

        /* 人口の総和を求める */
        sum_population += add_population(sum_area, &cities[i]);
    }
    
    /* 人口密度の平均値を求める */
    ave_density = sum_density / num_city;

    printf("-----------------------------------------\n");
    printf("面積の総和: %d [km2]\n", sum_area);
    printf("人口の総和: %.2f [万人]\n", sum_population);
    printf("人口密度の平均値: %.2f [人/km2]\n", ave_density);
}


