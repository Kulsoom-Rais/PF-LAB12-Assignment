#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, extra, i;
    float *sales;
    float total = 0;

  
    printf("Enter number of days: ");
    scanf("%d", &N);

  
    sales = (float *)malloc(N * sizeof(float));
    if (sales == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

 
    printf("Enter sales for %d days:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%f", &sales[i]);
        total += sales[i];
    }

 
    printf("Initial total sales = %.2f\n", total);

    
    printf("Enter number of extra days: ");
    scanf("%d", &extra);

    sales = (float *)realloc(sales, (N + extra) * sizeof(float));
    if (sales == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("Enter sales for %d extra days:\n", extra);
    for (i = N; i < N + extra; i++) {
        scanf("%f", &sales[i]);
        total += sales[i];
    }

  
    printf("Updated total sales = %.2f\n", total);

  
    free(sales);

    return 0;
}

