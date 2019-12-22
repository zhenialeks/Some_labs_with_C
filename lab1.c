#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define frand()(float) ((rand()/(RAND_MAX+1.0))*1000)*(rand()>(0.5)*RAND_MAX ? 1 : -1)

int main(){
    float A[20];
    for (int i = 0; i < 20; i++){
        A[i] = frand();
    }

    //Average
    double aver = 0;
    char aver_c = 0;
    for (int i = 0; i < 20; i++)
        if (A[i] > 0){
            aver += A[i];
            aver_c++;
        }
    aver /= aver_c;

    //Maximum of negativesx
    float max = -FLT_MAX;
    for (int i = 0; i < 20; i++)
        if (A[i] < 0 && A[i] > max)
            max = A[i];

    //New array
    float B[20];
    char pos = 0;
    for (int i = 0; i < 20; i++)
        if (A[i] > 0 && A[i] < aver)
            B[pos++] = A[i];


    printf("Исходный массив A:\n");
    for (int i = 0; i < 20; i++)
        printf("%.3f  ", A[i]);
    printf("\n");
    printf("Полученные результаты:\n");
    printf("MAX = %.3f\n", max);
    printf("AVERAGE = %.3f\n", aver);
    printf("Полученный массив B:\n");
    for (int i = 0; i < pos; i++){
        printf("%.3f  ", B[i]);
    }

    return 0;
}
