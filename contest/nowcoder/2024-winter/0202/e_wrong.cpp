#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 15;
typedef pair<int, int> com;

const int dp[] = { 3, 0, 1 };
const int dq[] = { 0, 3, 1 };


int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while ( t -- ) {
        int n, m, a[N];
        scanf("%d%d", &n, &m);
        for ( int i = 1; i <= n; i ++ )
            scanf("%d", &a[i]);
        while ( m -- ) {
            int p, q, c = 0;
            scanf("%d %d", &p, &q);
            if ( p == 1 || q == 1 ) {
                a[1] += 3;
            } else {
                int rm = -1, rma = -1;
                for ( int i = 0; i < 3; i ++ ) {
                    int s[] = { a[p] + dp[i], a[q] + dq[i], a[1] };
                    sort( s, s + 3, greater<int>() );
                    int rt = 1;
                    for ( int i = 0; i < 3; rt ++, i ++ )
                        if ( s[i] == a[1] )
                            break;
                    if ( !~rma || ( ~rma && rt < rm ) )
                        rm = rt, rma = i;
                }
                a[p] += dp[rma];
                a[q] += dq[rma];
            }
        }
        int a1 = a[1];
        sort( a + 1, a + n + 1, greater<int>() );
        int ans = 1;
        for ( int i = 1; i <= n; ans ++, i ++ )
            if ( a[i] == a1 )
                break;
        printf("%d\n", ans);
    }
    return 0;
}
