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
using namespace std;
typedef pair<int, int> pir;
typedef long long ll;
const int N = 2e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, k, ans = 0;
    int a[N];
    ll s[N] = {0};
    set<ll> x;
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i]);
        s[i] = s[ i - 1 ] + a[i];
        x.insert( s[ i - 1 ] % k );
        if ( x.count( s[i] % k ) ) {
            ans ++;
            x.clear();
        }
    }
    printf("%d\n", ans);
    return 0;
}
