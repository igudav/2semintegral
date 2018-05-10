#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "allthemath.h"

extern double f1(double);
extern double f2(double);
extern double f3(double);
extern double f4(double);
extern double f5(double);
extern double f6(double);

// функция-оболочка для тестирования функции root
double testRoot(void) {

    int f, g;
    double a, b, eps1;
    double (*funcF)(double);
    double (*funcG)(double);

    printf("f = ");
    if (scanf("%d", &f) != 1) {
        exit(1);
    }
    fgetc(stdin);
    printf("g = ");
    if (scanf("%d", &g) != 1) {
        exit(1);
    }
    fgetc(stdin);
    printf("a = ");
    if (scanf("%lf", &a) != 1) {
        exit(1);
    }
    printf("b = ");
    if (scanf("%lf", &b) != 1) {
        exit(1);
    }
    printf("eps1 = ");
    if (scanf("%lf", &eps1) != 1) {
        exit(1);
    }

    switch (f) {
        case 1:
            funcF = &f1;
            break;
        case 2:
            funcF = &f2;
            break;
        case 3:
            funcF = &f3;
            break;
        case 4:
            funcF = &f4;
            break;
        case 5:
            funcF = &f5;
            break;
        case 6:
            funcF = &f6;
            break;
        default:
            printf("Somthing went wrong(((\n");
            exit(1);
    }

    switch (g) {
        case 1:
            funcG = &f1;
            break;
        case 2:
            funcG = &f2;
            break;
        case 3:
            funcG = &f3;
            break;
        case 4:
            funcG = &f4;
            break;
        case 5:
            funcG = &f5;
            break;
        case 6:
            funcG = &f6;
            break;
        default:
            printf("Somthing went wrong(((\n");
            exit(1);
    }
    return root(funcF, funcG, a, b, eps1);
}

// функция-оболочка для тестирования функции integral
double testInt(void) {
    int f;
    double a, b, eps2;
    double (*funcF)(double);

    printf("f = ");
    if (scanf("%d", &f) != 1) {
        exit(1);
    }
    fgetc(stdin);
    printf("a = ");
    if (scanf("%lf", &a) != 1) {
        exit(1);
    }
    printf("b = ");
    if (scanf("%lf", &b) != 1) {
        exit(1);
    }
    printf("eps1 = ");
    if (scanf("%lf", &eps2) != 1) {
        exit(1);
    }

    switch (f) {
        case 1:
            funcF = &f1;
            break;
        case 2:
            funcF = &f2;
            break;
        case 3:
            funcF = &f3;
            break;
        case 4:
            funcF = &f4;
            break;
        case 5:
            funcF = &f5;
            break;
        case 6:
            funcF = &f6;
            break;
        default:
            printf("Somthing went wrong(((\n");
            exit(1);
    }

    return integral(funcF, a, b, eps2);
}

int main(int argc, char **argv) {

    int printIters = 0;
    int printX = 0;

    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-i") == 0) {
            printIters = 1;
        } else if (strcmp(argv[i], "-x") == 0) {
            printX = 1;
        } else if (strcmp(argv[i], "-help") == 0) {
            printf("OPTIONS:\n"
                   "-i print numbers of iterations to find a root\n"
                   "-x print x-coordinates of cross-points\n"
                   "-testroot test root function\n"
                   "-testint test integral funcion\n");
            return 0;
        } else if (strcmp(argv[i], "-testroot") == 0) {
            printf("%lf\n", testRoot());
            return 0;
        } else if (strcmp(argv[i], "-testint") == 0) {
            printf("%lf\n", testInt());
            return 0;
        }
    }


    double x12 = root(f1, f2, 0, 4, 0.000008);
    int i12 = getRootIters();
    double x23 = root(f2, f3, -1, -0.5, 0.000008);
    int i23 = getRootIters();
    double x13 = root(f1, f3, -5, -1, 0.000008);
    int i13 = getRootIters();

    double res = integral(f3, x13, x23, 0.00015);
    res += integral(f2, x23, x12, 0.00015);
    res += integral(f1, x12, x13, 0.00015);

    printf("%lf\n", res);

    if (printIters) {
        printf("%d - f1 x f2\n%d - f2 x f3\n%d - f1 x f3\n", i12, i23, i13);
    }
    if (printX) {
        printf("%lf - f1 x f2\n%lf - f2 x f3\n%lf - f1 x f3\n", x12, x23, x13);
    }

    return 0;
}
