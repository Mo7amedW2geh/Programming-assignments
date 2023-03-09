#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    int n = 0;
    float t = 1;
    float pi = 0;

    while(fabs(t) > pow(10, -4) ){
        t = (4 * pow(-1, n)) / (2*n + 1);
        pi = pi + t;
        n = n + 1;
    }
    printf("%f\n",pi);

    return 0;
}
