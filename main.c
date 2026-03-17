#include <stdio.h>
#include <stdbool.h>

long double root (int iterations);
long double add (long double addend0, long double addend1);
long double sub (long double minuend, long double subtrahend);
long double mul (long double factor0, long double factor1);
long double div (long double dividend, long double divisor);
long double 

int main (void) {

    int funky;
    int gnarly;

    printf("Please provide amount of iterations: ");
    scanf("%d", &funky);
    printf("\nPlease provide number of digits to display: ");
    scanf("%d", &gnarly);
    printf("\nThe square root of 2 is about equal to:\n|:%.*Lf:|\n", gnarly, root(funky));

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