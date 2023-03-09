#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    double x;

    printf("enter x: ");
    scanf("%lf", &x);

    int n = 2;
    double t = x;
    double sinx = 0;

    while(fabs(t) > pow(10, -6) ){
        sinx = sinx + t;
        t = t * (-pow(x, 2)) / (n * (n + 1));
        n = n + 2;
    }
    printf("sqrt(sin(%lf)) = %lf\n", x, sqrt(sinx));

    return 0;
}
