#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll ans = m;
        map<ll, ll> x;
        for ( int i = 1; i <= n; i ++ ) {
            ll a, b;
            scanf("%lld%lld", &a, &b);
            if ( x.find(a) == x.end() )
                x[a] = b;
            else x[a] += b;
        }
        map<ll, ll, greater<ll> > y;
        ll accu = 0;
        for ( auto e : x ) {
            accu += e.second;
            y[ e.first ] = e.first - accu;
        }
        for ( auto e : y )
            if ( e.second <= m ) {
                ans = e.first + m - e.second;
                break;
            }
        printf("%lld\n", ans);
    }
    return 0;
}
