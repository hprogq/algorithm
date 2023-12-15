#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
const int N = 10, INF = 0x3f3f3f3f;

int s, solved = 0;
ld rr, maxl = 0, maxr = 0;
ld nowl = 0, nowr = 0;

bool solve( int w[N], int sum[N], int l, int r, ld pos = 0 ) {
    if ( l == r ) {
        solved ++;
        nowl = min( nowl, pos );
        nowr = max( nowr, pos );
        // if ( nowl < maxl || nowr > maxr || nowr - nowl > maxr - maxl  )
        //     return false;
        // else 
        if( solved == s ) {
            if ( nowr - nowl > maxr - maxl && nowr - nowl <= rr )
                maxl = nowl, maxr = nowr;
            solved = nowl = nowr = 0;
        }
        return true;
    }
    for ( int i = l; i < r; i ++ ) {
        int totl = sum[ i + 1 ] - sum[ l ], totr = sum[ r + 1 ] - sum[ i + 1 ];
        ld lenl = 1.0 * totr / ( totl + totr ), lenr = 1 - lenl;
        if ( !solve( w, sum, l, i, pos - lenl ) )
            continue;
        if ( !solve( w, sum, i + 1, r, pos + lenr ) )
            continue;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        scanf("%Lf%d", &rr, &s);
        int w[N];
        for ( int i = 0; i < s; i ++ )
            scanf("%d", &w[i]);
        sort( w, w + s );
        maxl = maxr = 0;
        do {
            int sum[N] = { 0 };
            for ( int i = 0; i < s; i ++ )
                sum[ i + 1 ] = sum[i] + w[i];
            solve( w, sum, 0, s - 1 );
        } while ( next_permutation( w, w + s ) );
        ld ans = maxr - maxl;
        if ( ans == 0 )
            printf("%d\n", -1);
        else printf("%.16Lf\n", ans);
    }
    return 0;
}
