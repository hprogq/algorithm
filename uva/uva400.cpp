#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxl = 100 + 5;
const int len = 60;
int main() {
#ifdef LOCAL
    freopen("uva400.in", "r", stdin);
    freopen("uva400.out", "w", stdout);
#endif
    int n;
    while ( ~scanf("%d", &n) && n ) {
        string t[maxl];
        int m = 0;
        for ( int i = 1; i <= n; i++ ) {
            cin >> t[i];
            m = max(m, (int)t[i].length());
        }
        sort(t + 1, t + n + 1);
        for ( int i = 1; i <= len; i++ )
            printf("-");
        printf("\n");
        int c = ( len + 2 ) / ( m + 2 );
        int r = ceil( n * 1.0 / c );
        c = ceil( n * 1.0 / r );
        // printf("r: %d    c: %d\n", r, c);
        for ( int i = 1; i <= r; i++ ) {
            for ( int j = 1; j <= c; j++ ) {
                // printf("%d", ( j - 1 ) * r + i);
                int w = ( j - 1 ) * r + i;
                if ( w > n )
                    break;
                cout << t[w];
                int ex = ( j == c || ( j == c - 1 && ( c - 1 ) * r + i > n ) ) ? 0 : 2;
                // printf("%d %d %d", c, r, i);
                for ( int k = 1; k <= m + ex - t[w].length(); k++ )
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
