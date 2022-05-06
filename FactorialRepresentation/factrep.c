#include <stdio.h>

#define N 3

void main(void){
    int i = 0;
    int k;
    int c[N + 2];
    // initialize
    for(k = 1; k <= N + 1; k++){
        c[k] = 0;
    }

    do{
        printf("%3d:", i++);
        for(k = N; k >= 1; k--){
            printf(" %d", c[k]);
        }
        printf("\n");
        k = 1;
        while (c[k] == k)
        {
            c[k] = 0;
            k++;
        }
        c[k]++;
    }while(k <= N);
}

/*
  0: 0 0 0
  1: 0 0 1
  2: 0 1 0
  3: 0 1 1
  4: 0 2 0
  5: 0 2 1
  6: 1 0 0
  7: 1 0 1
  8: 1 1 0
  9: 1 1 1
 10: 1 2 0
 11: 1 2 1
 12: 2 0 0
 13: 2 0 1
 14: 2 1 0
 15: 2 1 1
 16: 2 2 0
 17: 2 2 1
 18: 3 0 0
 19: 3 0 1
 20: 3 1 0
 21: 3 1 1
 22: 3 2 0
 23: 3 2 1
*/