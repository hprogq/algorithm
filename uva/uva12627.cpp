#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long c[31] = { 1 };

long long solve( int k, int a ) {
    if ( !a )
        return 0;
    if ( !k )
        return 1;
    long long f = 1 << ( k - 1 );
    if ( a > f )
        return 2 * c[ k - 1 ] + solve( k - 1, a - f );
    else return 2 * solve( k - 1, a );
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    for( int i = 1; i <= 30; i ++ )
        c[i] = 3 * c[ i - 1 ];
    int v;
    scanf("%d", &v);
    for ( int i = 1; i <= v; i ++ ) {
        printf("Case %d: ", i);
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        printf("%lld\n", solve( k, b ) - solve( k, a - 1 ));
    }
    return 0;
}
