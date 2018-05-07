#include "allthemath.h"

double root (double (*f)(double), double (*g)(double),
             double a, double b, double eps1) {
    iters = 0;
    double mid = (a + b) / 2;
    int isInc = 1; // если неубывающая, то 1

    // выставляем флаг возрастания/убывания
    if (f(a) - g(a) > f(b) - g(b)) {
        isInc = 0;
    }

    while (b - a >= eps1) {
        mid = (a + b) / 2;
        if (f(mid) - g(mid) > 0 && !isInc || f(mid) - g(mid) <= 0 && isInc) {
            a = mid;
        } else {
            b = mid;
        }
        ++iters;
    }

    return mid;
}

int getRootIters(void) {
    return iters;
}

double integral (double (*f)(double), double a, double b, double eps2) {
    int n = 20; // начинаем с 20 итераций
    double intOld; // старое значение интеграла для сравнения
    double delta = (b - a) / n; // шаг
    double ends = 0.0; // концы в формуле (f(a) + f(b))
    double evenPart = 0.0; // часть, куда входят точки с четными индексами
    double nevenPart = 0.0; // с нечетными
    double integr; // новый интеграл
    double k = (b - a) / (6 * n); // коэффициент

    ends += f(a) + f(b);
    ends *= k;

    for (int i = 1; i < n; ++i) {
        evenPart += 2 * f(a + i * delta);
    }
    evenPart *= k;

    for (int j = 0; j < n; ++j) {
        nevenPart += 4 * f(a + j * delta + delta / 2);
    }
    nevenPart *= k;

    integr = ends + evenPart + nevenPart;

    do {
        // удваиваем число отрезков
        intOld = integr;
        n *= 2;
        delta /= 2;
        k /= 2;
        ends /= 2;
        evenPart = nevenPart / 4 + evenPart / 2; // не считаем посчитанное
        nevenPart = 0.0;
        for (int j = 0; j < n; ++j) {
            nevenPart += 4 * f(a + j * delta + delta / 2);
        }
        nevenPart *= k;

        integr = ends + evenPart + nevenPart;

    // правило Рунге
    } while (integr - intOld >= eps2 * 15 || integr - intOld <= -eps2 * 15);

    return integr;
}