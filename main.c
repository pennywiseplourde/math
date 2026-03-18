#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sign (int integer);
long double root (int iterations);
long double add (long double addend0, long double addend1);
long double sub (long double minuend, long double subtrahend);
long double mul (long double factor0, long double factor1);
long double divide (long double dividend, long double divisor);
long double expon (long double base, int order);

int main (int argc, char *argv[]) {

    const char *yucky = argv[0];
    char *endptr1;
    char *endptr2;
    const long double funky = strtold(argv[1], &endptr1);
    const long double gnarly = strtold(argv[2], &endptr2);

    if (strcmp(yucky, "exp")) {
        printf("|:%.12Lf:|", expon(funky, gnarly));
        return 0;
    }

}

int sign (int integer) {

    if (integer < 0) {
        return 0;
    } else return 1;
}

long double root (int iterations) {

    long double ptr = 1;
    long double cur;
    int ticker = 0;
    bool done = false;

    while (!done) {
    
    cur = 2 / ptr;
    cur += ptr;
    cur /= 2;
    ptr = cur;

    ticker += 1;
    if (ticker == iterations) {
        done = true;
    }

    }

    return ptr;
}

long double expon (long double base, int order) {

    int orderabs = abs(order);
    int ordersign = sign(order);
    long double cur = 1;

    for (int i = 0; i < orderabs; i++) {
        cur *= base;

        if (ordersign == 0) {
            cur *= -1;
        }
    }

    return cur;
}

