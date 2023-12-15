#include <stdio.h>
#include <math.h>
typedef long long ll;
int main() {
    ll n, maxl = -1, s = -1;
    scanf("%lld", &n);
    for ( ll i = 2, j = 2, x = n; i <= sqrt(x); j = ++i, x = n ) {
        if ( x % j )  continue;
        while ( !( x % j ) )  x /= ( j ++ );
        if ( j - i > maxl )  maxl = j - i, s = i;
    }
    if ( s == -1 )  maxl = 1, s = n;
    printf("%lld\n", maxl);
    while ( !( n % s ) && ( n /= s ) )
        printf("%lld%s", s, n % ( s + 1 ) ? "" : "*"), s++;
    printf("\n");
    return 0;
}
