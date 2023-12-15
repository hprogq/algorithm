#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
const int N = 2e5;
typedef pair<int, int> pir;

void insert_st( set<pir>& st, pir x ) {
    auto it = st.insert(x).first;
    if ( it == st.begin() )
        return;
    auto prevIt = prev(it);
    if ( (*prevIt).second >= (*it).second ) {
        st.erase( it );
        return;
    }
    auto nextIt = next(it);
    while ( nextIt != st.end() && (*nextIt).second <= (*it).second )
        st.erase( nextIt ++ );
    return;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int n, ans = 1, a[N];
        scanf("%d", &n);
        for ( int i = 0; i < n; i ++ )
            scanf("%d", &a[i]);
        int f[N] = { 0 }, g[N] = { 1, 0 };
        int L = 0, R = 1;
        while ( L < n ) {
            while ( R < n && ( a[R] > a[ R - 1 ] || L == R ) )
                g[R] = R - L + 1, R ++;
            f[L] = R - L, L ++;
        }
        set<pir> st;
        for ( int i = 0; i < n - 1; i ++ ) {
            insert_st( st, pir( a[i], g[i] ) );
            if ( !st.empty() ) {
                auto it = st.lower_bound( pir( a[ i + 1 ], 0 ) );
                if ( it != st.begin() )
                    ans = max( ans, f[ i + 1 ] + (* --it).second );
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
