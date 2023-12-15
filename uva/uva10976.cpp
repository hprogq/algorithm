#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int k;
    while ( ~scanf("%d", &k) ) {
        int sum = 0;
        for ( int y = k + 1; y <= 2 * k; y ++ ) {
            int x = ( k * y ) / ( y - k );
            if ( x * y == k * ( x + y ) )
                sum ++;
        }
        printf("%d\n", sum);
        for ( int y = k + 1; y <= 2 * k; y ++ ) {
            int x = ( k * y ) / ( y - k );
            if ( x * y == k * ( x + y ) )
                printf("1/%d = 1/%d + 1/%d\n", k, x, y);
        }
    }
    return 0;
}
