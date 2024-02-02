#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pos;

bool check( pos x, pos y ) {
    pos d( abs(x.first - y.first), abs(x.second - y.second) );
    return ~x.second && ~y.second && d.second == 1 && ( d.first == 0 || d.first == 1 );
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int n;
        scanf("%d", &n);
        set<pos> g;
        while ( n -- ) {
            int r, c;
            scanf("%d%d", &r, &c);
            g.insert( pos( c, r ) );
        }
        int sum[2] = {0}, ans = 0;
        bool line[2] = {false}, left = false, right = false, mid = false;
        pos last(-1, -1);
        for ( pos e : g ) {
            if ( e.first <= 0 ) {
                line[0] |= check( e, last );
                left |= e == pos(-1, 1);
                sum[0] ++;
            }
            if ( e.first >= 0 ) {
                if ( e.first > 0 )
                    line[1] |= check( e, last );
                right |= e == pos(1, 1);
                sum[1] ++;
            }
            mid |= e == pos(0, 2);
            last = e;
        }
        if ( !line[0] ) {
            if ( !sum[0] )
                ans += 2, mid = true, sum[1] ++, line[1] |= right;
            else {
                if ( left )
                    mid = true, sum[1] ++, line[1] |= right;
                ans += 1;
            }
        }
        if ( !line[1] ) {
            if ( !sum[1] )
                ans += 2;
            else ans += 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
