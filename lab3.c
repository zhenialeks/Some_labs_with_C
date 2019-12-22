#include <stdio.h>
#include <malloc.h>
#define Matrix struct matrix

struct matrix {
    int **el;
    int n;
    int m;
};

Matrix *create_matrix(int n, int m){
    if (n == 0 || m == 0); //todo: handle that case

    Matrix *mat = malloc(sizeof(Matrix));
    mat -> n = n;
    mat -> m = m;
    mat -> el = malloc(sizeof(int *)*n);
    for (int i = 0; i < n; i++) {
        mat -> el[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            mat -> el[i][j] = 0;
    }
    return mat;
}

void print_matrix(Matrix *mat){
    for (int i = 0; i < mat->n; i++){
        for (int j = 0; j < mat->m; j++)
            printf("%d ", mat->el[i][j]);
        printf("\n");
    }
}

int find_least_negative_number(Matrix *mat){
    int min = 0;
    for (int i = 0; i < mat->n; i++)
        for (int j = 0; j < mat->m; j++)
            if (mat->el[i][j] < 0 && mat->el[i][j] < min)
                min = mat->el[i][j];

    return min;
}

int *sums(Matrix *mat){
    long sum_plus  = 0;
    long sum_minus = 0;
    for (int i = 0; i < mat->n; i++)
        for (int j = 0; j < mat->m; j++)
            if (mat->el[i][j] > 0) sum_plus += mat->el[i][j];
            else                  sum_minus += mat->el[i][j];

    int *res;
    res = malloc(sizeof(int) * 2);
    res[0] = sum_plus;
    res[1] = sum_minus;
    return res;
}

int main() {

    Matrix *mat = create_matrix(2, 4);


    return 0;
}