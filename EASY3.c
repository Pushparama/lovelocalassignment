#include <stdio.h>
#include <stdlib.h>

int** PascalsTriangle(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        result[i] = malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        result[i][0] = result[i][i] = 1;

        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }

    return result;
}

void printPascalsTriangle(int** triangle, int numRows, int* columnSizes) {
    printf("[");
    for (int i = 0; i < numRows; i++) {
        printf("[");
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d", triangle[i][j]);
            if (j < columnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < numRows - 1) {
            printf(",");
        }
        
    }
    printf("]\n");
}

void freePascalsTriangle(int** triangle, int numRows, int* columnSizes) {
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(columnSizes);
}

int main() {
    int numRows;
    
    scanf("%d", &numRows);

    int returnSize;
    int* returnColumnSizes;

    int** result = PascalsTriangle(numRows, &returnSize, &returnColumnSizes);

    printPascalsTriangle(result, numRows, returnColumnSizes);
    freePascalsTriangle(result, numRows, returnColumnSizes);

    return 0;
}
