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
const int N = 2e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, k, ans = 0;
    int a[N], s[N] = {0};
    set<int> x;
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i]);
        s[i] += a[i];
        if ( x.count( s[i] % k ) ) {
            ans ++;
            x.clear();
        }
        x.insert( s[ i - 1 ] % k );
    }
    printf("%d\n", ans);
    return 0;
}
