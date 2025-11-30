#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char *str;   
};

int main() {
    int n, i, j;
    char temp[200];            
    struct String *arr;       

   
    printf("Enter number of strings: ");
    scanf("%d", &n);

    
    arr = (struct String *)malloc(n * sizeof(struct String));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

   
    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", temp);

        arr[i].str = (char *)malloc(strlen(temp) + 1);
        strcpy(arr[i].str, temp);
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i].str, arr[j].str) > 0) {
                char *swap = arr[i].str;
                arr[i].str = arr[j].str;
                arr[j].str = swap;
            }
        }
    }

   
    printf("\nSorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i].str);
    }

   
    for (i = 0; i < n; i++) {
        free(arr[i].str);
    }
    free(arr);

    return 0;
}

