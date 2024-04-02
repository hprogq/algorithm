#include <iostream>
#include <algorithm>
using namespace std;
const int M = 7;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, t, s = 0, ans = 0, f[M] = {0}, l[M] = {0};
    scanf("%d", &n);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &t);
        s = ( s + t % M ) % M;
        f[s] = f[s] ? f[s] : ( s ? i : 0 );
        l[s] = i;
    }
    for ( int i = 0; i < M; i ++ )
        if ( l[i] )
            ans = max( ans, l[i] - f[i] );
    printf("%d\n", ans);
    return 0;
}
