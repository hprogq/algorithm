#include <iostream>
#include <cmath>
using namespace std;
const int N = 5e6 + 10;
int main() {
    int v;
    scanf("%d\n", &v);
    for ( int c = 1; c <= v; c ++ ) {
        int n, t, d[N], s[N] = {0}, maxn = 0;
        printf("Case #%d: ", c);
        scanf("%d\n", &n);
        for ( int i = 1; i <= n; i ++ ) {
            scanf("%c", &t);
            d[i] = t - '0';
        }
        int f = ceil( n / 2.0 );
        for ( int i = 1; i <= n; i ++ ) {
            s[i] = s[ i - 1 ] + d[i];
            if ( i >= f )
                maxn = max( maxn, s[i] - s[ i - f ] );
        }
        printf("%d\n", maxn);
    }
}