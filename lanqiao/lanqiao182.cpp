#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, a[N], maxn = 0;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    int time = 0, clock[N] = { 0 };
    for ( int i = 1; i <= n; i ++ ) {
        if ( clock[i] )
            continue;
        int cur = i, start = time ++;
        while ( !clock[cur] )
            clock[cur] = time ++, cur = a[cur];
        if ( clock[cur] > start )
            maxn = max( maxn, time - clock[cur] );
    }
    printf("%d\n", maxn);
    return 0;
}
