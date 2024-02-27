#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;
typedef pair<int, int> pir;
const int N = 1e3 + 10;

long long msum( int a[], int n ) {
    long long sum = 0, maxs = LLONG_MIN;
    for ( int i = 1; i <= n; i ++ ) {
        sum += a[i];
        maxs = max( maxs, sum );
        if ( sum < 0 )
            sum = 0;
    }
    return maxs;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, k, l;
    long long ans = LLONG_MIN;
    scanf("%d%d", &n, &k);
    int a[N];
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    if ( k )
        for ( int i = 1; i < n; i ++ ) {
            swap( a[i], a[i + 1] );
            ans = max( ans, msum( a, n ) );
            swap( a[i], a[i + 1] );
        }
    else ans = msum( a, n );
    printf("%lld\n", ans);
    return 0;
}
