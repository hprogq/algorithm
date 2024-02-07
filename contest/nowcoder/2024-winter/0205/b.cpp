#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pir;
const int N = 350;
map<pir, bool> c;
set<pir> l[2];

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int walk(pir k) {
    int res = 0;
    c[k] = true;
    for ( int i = 0; i <= 1; i ++ )
        for ( int j = 0; j <= 1; j ++ ) {
            int x = k.first, y = k.second;
            if ( i )
                swap( x, y );
            pir t( x + j, y );
            if ( l[i].find(t) == l[i].end() ) {
                res ++;
                l[i].insert(t);
            }
        }
    for ( int i = 0; i < 4; i ++ ) {
        pir nxt(k.first + dx[i], k.second + dy[i]);
        if ( c.find(nxt) != c.end() && !c[nxt] )
            res += walk( nxt );
    }
    return res;
}

int main() {
    int n, m, k, w = 0;
    scanf("%d%d%d", &n, &m, &k);
    while ( k -- ) {
        int x, y;
        scanf("%d%d", &x, &y);
        c[pir(x, y)] = false;
    }
    for ( auto e : c )
        if ( !e.second )
            w += walk(e.first);
    printf("%d", w);
    return 0;
}
