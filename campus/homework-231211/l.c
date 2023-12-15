#include <stdio.h>
#define N 10

double aver( double s[N] ) {
    double sum = 0;
    for ( int i = 0; i < N; i ++ )
        sum += s[i];
    return sum / N;
}

int main() {
    double s[N];
    for ( int i = 0; i < N; i ++ )
        scanf("%lf", &s[i]);
    printf("%.2lf\n", aver(s));
    return 0;
}
