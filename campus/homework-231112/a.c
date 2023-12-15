#include <stdio.h>
#include <math.h>
int main() {
    int cnt = 0, k;
    for ( int n = 50; n <= 120; n++ ) {
        for ( int i = 2; i <= sqrt(n) && ( k = n % i ); i++ );
        if ( k )  printf("%3d%c", n, !(++cnt % 5) ? '\n' : '\t');
    }
    return 0;
}
