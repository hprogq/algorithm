// 注意：本题每个顶点只要当前连续穿过的障碍数不同，就被允许重复经过。
// 因为：进入某点时的连续穿过的障碍数，会影响接下来从该点出发的路径的可行性。

#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;
const int N = 22;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

typedef pair<int, int> pos;
typedef tuple<pos, int, int> stat;  // position, blocked, steps

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int m, n, k, a[N][N];
        scanf("%d%d%d", &m, &n, &k);
        for ( int i = 0; i < m; i ++ )
            for ( int j = 0; j < n; j ++ )
                scanf("%d", &a[i][j]);
        if ( m == 1 && n == 1 ) {
            printf("0\n");
            continue;
        }
        queue<stat> que;
        bool vis[N][N][N] = { false }, flag = false;
        que.push( stat( pos(0, 0), 0, 0 ) );
        vis[0][0][0] = true;
        while ( !flag && !que.empty() ) {
            auto [ ppos, pblock, pstep ] = que.front();
            que.pop();
            for ( int i = 0; i < 4; i ++ ) {
                int nx = ppos.first + dx[i], ny = ppos.second + dy[i];
                pos npos( nx, ny );
                if ( !( npos.first >= 0 && npos.second >= 0 && npos.first < m && npos.second < n ) || vis[nx][ny][ a[nx][ny] ? pblock + 1 : 0 ] || pblock + a[npos.first][npos.second] > k )
                    continue;
                vis[nx][ny][ a[nx][ny] ? pblock + 1 : 0 ] = true;
                if ( npos == pos( m - 1, n - 1 ) ) {
                    printf("%d\n", pstep + 1);
                    flag = true;
                    break;
                } else que.push( stat( npos, a[nx][ny] ? pblock + 1 : 0, pstep + 1 ) );
            }
        }
        if ( !flag )
            printf("-1\n");
    }
    return 0;
}
