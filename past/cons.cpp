#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
#ifdef LOCAL
    freopen("temp2.out", "w", stdout);
#endif
    ll n;
    // scanf("%d", &n);
    for ( n = 2147483000; n <= 2147483647; n++ ) {
        ll maxl = -1, s = -1;
        for ( ll i = 2, j = 2, x = n; i <= sqrt(x); j = ++i, x = n ) {
            if ( x % j )  continue;
            while ( !( x % j ) )  x /= ( j ++ );
            if ( j - i > maxl )  maxl = j - i, s = i;
        }
        if ( s == -1 )  maxl = 1, s = n;
        printf("%lld\n", maxl);
        ll p = n;
        while ( !( p % s ) && ( p /= s ) )
            printf("%lld%s", s, ( p == 1 || p % ++s ) ? "" : "*");
        printf("\n\n");
    }
    return 0;
}