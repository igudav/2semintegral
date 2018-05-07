//
// Created by igudav on 30.04.18.
//

#ifndef TASK6_ALLTHEMATH_H
#define TASK6_ALLTHEMATH_H

// число итераций при поиске корня уравнения
int iters;

double root (double (*f)(double), double (*g)(double),
             double a, double b, double eps1);

int getRootIters(void);

double integral (double (*f)(double), double a, double b, double eps2);

#endif //TASK6_ALLTHEMATH_H
