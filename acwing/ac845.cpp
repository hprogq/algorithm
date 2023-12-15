#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;
typedef pair<string, int> step;
const int n = 3,
          dr[] = { 0, 1, 0, -1 },
          dc[] = { 1, 0, -1, 0 };

bool valid_axis( int r, int c ) {
    return ( r >= 0 && r < n && c >= 0 && c < n );
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int minn = 0x3f3f3f3f;
    string start, end = "12345678x";
    start.resize( n * n );
    for ( int i = 0; i < n * n; i ++ )
        scanf( "%s", start.c_str() + i );
    queue<step> que;
    unordered_set<string> vis;
    que.push( step( start, 0 ) );
    while ( !que.empty() ) {
        step x = que.front();
        string t = x.first;
        que.pop();
        if ( t == end ) {
            printf("%d\n", x.second);
            return 0;
        }
        int k = t.find('x');
        int r = k / 3, c = k % 3;
        for ( int i = 0; i < 4; i ++ ) {
            int tr = r + dr[i], tc = c + dc[i];
            if ( valid_axis( tr, tc ) ) {
                string next = t;
                int p = tr * n + tc;
                swap( next[p], next[k] );
                if ( !vis.count(next) ) {
                    vis.insert(next);
                    que.push( step( next, x.second + 1 ) );
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}