#include <stdio.h>

void main(void){
    int m, n, q;

    printf(" 分子 m = ");
    scanf("%d", &m);
    printf(" 分母 n = ");
    scanf("%d", &n);
    printf("%d / %d = ", m, n);

    while (n % m != 0)
    {
        q = n / m + 1;
        printf("1 / %d + ", q);
        m = m * q - n;
        n *= q;
    }
    printf("1 / %d\n", n / m);
    return;
}

/*
 分子 m = 10
 分母 n = 15
10 / 15 = 1 / 2 + 1 / 6
*/
/*
 分子 m = 30
 分母 n = 75
30 / 75 = 1 / 3 + 1 / 15
*/