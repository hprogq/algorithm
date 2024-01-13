#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    for ( int c = 1; c <= v; c ++ ) {
        printf("Case %d: ", c);
        int n, p[N], q[N], s = 0;
        scanf("%d", &n);
        for ( int i = 1; i <= n; i ++ )
            scanf("%d", &p[i]), s += p[i];
        for ( int i = 1; i <= n; i ++ )
            scanf("%d", &q[i]), s -= q[i];
        int oil = 0, pos = 1, start;
        if ( s < 0 )
            printf("Not possible\n");
        else {
            while ( pos <= n ) {
                start = pos, oil = 0;
                while ( pos <= n && oil >= 0 )
                    oil += p[pos] - q[pos], pos ++;
            }
            printf("Possible from station %d\n", start);
        }
    }
    return 0;
}
