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
long double root (long double base, long double index);
long double expon (long double base, int order);
int run (char *a[]);

int main (int argc, char *argv[]) {

    const char *yucky = argv[1];
    char *smelly;
    bool done = false;
    char *a[] = {argv[1], argv[2], argv[3]};
    bool persistant = false;
    char buffer[128];
    bool skip = false;

    int works;

    if (argc < 2) {

        persistant = true;
        skip = true;

    } else if (strcmp(yucky, "-p") == 0) {

        persistant = true;
        skip = true;
        
    }

    if (argc < 3 && !skip) {

        return err(3, "Operation Missing");

    } 
    
    if (argc < 4 && !skip) {

        return err(4, "Insufficient Arguments");

    }

    if (argc == 5) {

        smelly = argv[4];

        if (strcmp(smelly, "-p") == 0) {

            persistant = true;

        }

    }
    
    while (!done) {

        if (!skip) {

            works = run(a);
            skip = false;

        }

        if (works == 2) {

            done = false;
            return err(5, "a[0] string copy failure");
            break;

        }

        if (works == 1) {

            done = true;
            return err(2, "Invalid Operation");
            break;

        }

        if (works == 5) {

            done = true;
            return 0;
            break;

        }


        if (!persistant) {

            done = true;
            break;

        }

        printf("\n> ");

        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%s %s %s", a[0], a[1], a[2]);

    }

 return 0;
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

long double add(long double addend0, long double addend1) {

    return (addend0 + addend1);

}

long double sub (long double minuend, long double subtrahend) {

    return (minuend - subtrahend);

}

long double mul (long double factor0, long double factor1) {

    return (factor0 * factor1);

}

long double divide (long double dividend, long double divisor) {

    return (dividend / divisor);

}

long double root (long double base, long double index) {

    long double ptr = 1;
    long double cur;
    int ticker = 0;
    bool done = false;

    while (!done) {
    
    cur = base / ptr;
    cur += ptr;
    cur /= index;
    ptr = cur;

    ticker += 1;
    if (ticker == 30) {
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

int run (char *a[]) {

    char *endptr1;
    char *endptr2;
    char *yucky;
    long double funky;
    long double gnarly;    
    long double temp;

    if (a[0] != NULL) {

        yucky = a[0];

    } else {

        return 2;

    }

    if (a[1] != NULL) {

        funky = strtold(a[1], &endptr1);

    }
    
    if (a[1] != NULL) {

        gnarly = strtold(a[2], &endptr2);

    }

    //  printf("%s %Lf %Lf %s %s %s", yucky, funky, gnarly, a[0], a[1], a[2]);

    if (strcmp(yucky, "add") == 0) {

            temp = add(funky, gnarly);

            printf("\nThe sum of %s and %s is: ", a[1], a[2]);
            printf("|:%Lf:|\n", temp);
            return 0;

        } else if (strcmp(yucky, "sub") == 0) {

            temp = sub(funky, gnarly);

            printf("\nThe difference between %s and %s is: ", a[1], a[2]);
            printf("|:%Lf:|\n", temp);
            return 0;

        } else if (strcmp(yucky, "mul") == 0) {

            temp = mul(funky, gnarly);

            printf("\nThe product of %s and %s is: ", a[1], a[2]);
            printf("|:%Lf:|\n", temp);
            return 0;

        } else if (strcmp(yucky, "div") == 0) {

            temp = divide(funky, gnarly);

            printf("\nThe quotient of %s and %s is: ", a[1], a[2]);
            printf("|:%Lf:|\n", temp);
            return 0;

        } else if (strcmp(yucky, "root") == 0) {

            temp = root(funky, gnarly);

            printf("\nThe %sa root of %s is: ", a[2], a[1]);
            printf("|:%Lf:|\n", temp);
            return 0;

        } else if (strcmp(yucky, "exp") == 0) {

            temp = expon(funky, gnarly);

            printf("\n%s raised to the power of %s is: ", a[1], a[2]);
            printf("|:%Lf:|\n", temp);
            return 0;

        } else if (strcmp(yucky, "exit") == 0) {

            return 5;

        } else {

            return 1;

    }

    return 0;

}