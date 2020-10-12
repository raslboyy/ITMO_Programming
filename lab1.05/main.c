#include <stdio.h>

int main(){

    const int size_array = 6;
    int array[6] = {34, 45, 56, 67, 78, 89};
    printf("[");
    for (int i = 0; i < size_array - 1; i++)
        printf("%d, ", array[i]);
    printf("%d]\n", array[size_array-1]);

    int matrix_A[2][2] = {{1, 0},
                         {1, 4}};
    int matrix_B[2][2] = {{1, 2},
                         {0, 1}};
    int matrix_C[2][2] = {};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
                matrix_C[i][j] = matrix_A[i][0] * matrix_B[0][j] + matrix_A[i][1] * matrix_B[1][j];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", matrix_C[i][j]);
        printf("\n");
    }

    return 0;
}
