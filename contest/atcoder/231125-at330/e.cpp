#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int N = 2e5 + 10;

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, q, mex, p[N], minn = 0, c;
    set<int> s;
    scanf("%d%d", &n, &q);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &p[i]);
        if ( !s.count( p[i] ) )
            s.insert( p[i] );
    }
    auto it = s.begin();
    while ( it != s.end() ) {
        if ( minn == *it ) {
            it ++;
            minn ++;
        } else break;
    }
    while ( q -- ) {
        int i, x;
        scanf("%d%d", &i, &x);
        p[i] = x;
        if ( !s.count(x) )
            s.insert(x);
        while ( !s.empty() ) {
            if ( minn == *s.begin() ) {
                s.erase( s.begin() );
                minn ++;
            } else break;
        }
        printf("%d\n", minn);
    }
    return 0;
}
