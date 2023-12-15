#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30, A = 26, INF = 0x3f3f3f3f;

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    string s;
    while ( cin >> s && s[0] != '#' ) {
        int h[N], e[N], ne[N], a[A], idx = 0, alp = 0;
        bool vis[N][N] = { false }, vis_alpha[N] = { false };
        bool loop = false;
        int from;
        
        memset( h, -1, sizeof(h) );

        for ( int i = 0; i < s.length(); i ++ ) {
            int t = (int) s[i] - 'A';
            vis_alpha[t] = true;
            if ( !loop )
                loop = true, from = t, i ++;
            else {
                if ( !vis[from][t] )
                    vis[from][t] = vis[t][from] = true, e[idx] = t, ne[idx] = h[from], h[from] = idx ++;
                if ( i + 1 == s.length() || s[ i + 1 ] == ';' )
                    loop = false, i ++;
            }
        }

        for ( int i = 0; i < A; i ++ )
            if ( vis_alpha[i] )
                a[ alp ++ ] = i;
        
        int ans = INF, best[A];
        do {
            bool skip = false;
            int b = -1, it[26] = { 0 };
            for ( int i = 0; i < alp; i ++ )
                it[ a[i] ] = i;
            for ( int i = 0; !skip && i < alp; i ++ )
                for ( int j = h[ a[i] ]; !skip && ~j; j = ne[j] ) {
                    int t = abs( i - it[ e[j] ] );
                    if ( t > ans )
                        skip = true;
                    else b = max( b, t );
                }
            if ( !skip && ~b && ans > b ) {
                ans = b;
                memcpy( best, a, sizeof(a) );
            }
        } while( next_permutation( a, a + alp ) );

        for ( int i = 0; i < alp; i ++ )
            printf("%c ", (char) best[i] + 'A');
        printf("-> %d\n", ans);
    }
    return 0;
}
