// 对拍用：暴力。
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
const int d[2][5] = {
    { 0, 2, 4, 6, 8 },
    { 1, 3, 5, 7, 9 }
};
int sum(ll x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int bits(ll x) {
    int sum = 0;
    while (x) {
        sum ++;
        x /= 10;
    }
    return sum;
}
int poww(int n) {
    ll p = 1;
    while ( n -- )
        p *= 10;
    return p;
}
const int N = 1e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.ans", "w", stdout);
#endif
    int n;
    ll ans = 0;
    scanf("%d", &n);
    ll a[N];
    for ( int i = 1; i <= n; i ++ )
        scanf("%lld", &a[i]);
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= n; j ++ )
            if ( i != j && ( 1LL * poww(bits(a[j])) * a[i] + a[j] ) % 36 == 0 ) {
                // printf("%lld\n", ( 1LL * poww(bits(a[j])) * a[i] + a[j] ));
                ans ++;
            }
    printf("%lld\n", ans);
    return 0;
}
