#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int X = ( 1 << 8 ) + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, u = 0;
    while ( scanf("%d", &n) && n ) {
        printf("S-Tree #%d:\n", ++ u);
        char s[3];
        int w[9], x[X];
        for ( int i = 1; i <= n; i ++ ) {
            scanf("%s", s);
            w[ s[1] - '0' ] = i;
        }
        char t[X];
        scanf("%s", t + 1);
        for ( int i = 0; i < 1 << n; i ++ )
            x[i] = t[i + 1] - '0';
        int v;
        scanf("%d", &v);
        while ( v -- ) {
            int q, c = 0;
            scanf("%d", &q);
            for ( int i = 0; i < n; i ++ ) {
                int p = q % 10;
                c += p * ( 1 << ( n - w[ n - i ] ) );
                q /= 10;
            }
            printf("%d", x[c]);
        }
        printf("\n\n");
    }
    return 0;
}