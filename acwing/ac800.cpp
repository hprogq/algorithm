#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m, x, a[N], b[N];
    scanf("%d%d%d", &n, &m, &x);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i <= m; i++ )
        scanf("%d", &b[i]);
    for ( int i = 1, j = 1; i <= n; i++ ) {
        int f = 0x7fffffff;
        while ( a[i] + b[j] - x > 0 )  j--;
        while ( j <= m && abs( a[i] + b[j] - x ) < f )  f = abs( a[i] + b[j++] - x );
        if ( a[i] + b[ -- j ] == x ) {
            printf("%d %d\n", i - 1, j - 1);
            return 0;
        }
    }
    return 0;
}
