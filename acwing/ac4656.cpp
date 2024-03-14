#include <iostream>
#include <set>
#include <functional>
using namespace std;
typedef pair<int, int> pir;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    long long ans = 0;
    multiset< pir, greater<pir> > s; // set内元素不重复
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        s.insert( pir(a, b) );
    }
    while ( m -- ) {
        auto [ a, b ] = *s.begin();
        s.erase( s.begin() );
        ans += a;
        if ( a - b > 0 )
            s.insert( pir( a - b, b ) );
    }
    printf("%lld\n", ans);
    return 0;
}
