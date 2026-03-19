#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int err (int code, char *str);
int sign (int integer);
long double add (long double addend0, long double addend1);
long double sub (long double minuend, long double subtrahend);
long double mul (long double factor0, long double factor1);
long double divide (long double dividend, long double divisor);
long double root (int iterations);
long double expon (long double base, int order);

int main (int argc, char *argv[]) {

    const char *yucky = argv[0];
    char *endptr1;
    char *endptr2;
    long double funky;
    long double gnarly;
    long double temp;

    if (argv[2] != NULL) {

        funky = strtold(argv[2], &endptr1);

    }
    
    if (argv[3] != NULL) {

        gnarly = strtold(argv[3], &endptr2);

    }
    
    if (strcmp(yucky, "exp") == 0) {

        temp = expon(funky, gnarly);

        printf("\n%s raised to the power of %s is:\n", argv[2], argv[3]);
        printf("|:%Lf:|\n", temp);
        printf("%d", strcmp(yucky, "exp"));
        return 0;
    }


 return err(2, "Function called is undefined");
}

int err(int code, char *str) {

    printf("\nExit Code %d: %s\n", code, str);

    return code;

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
    long double oneNeg = -1;
    long double cur = 1;

    for (int i = 0; i < orderabs; i++) {
        cur *= base;

        if (ordersign == 0) {
            cur *= oneNeg;
        }
    }

    return cur;
}

