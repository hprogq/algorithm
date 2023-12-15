#include <iostream>
using namespace std;
const int N = 110;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

struct node {
    int x, y;
    int d;
} q[ N * N ];

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    bool g[N][N] = { false };
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= m; j ++ )
            scanf("%d", &g[i][j]);
    int h = 0, t = 0, ans = 0;
    q[t].x = 1, q[t].y = 1, q[t].d = 0;
    while ( h <= t ) {
        int tx = q[h].x, ty = q[h].y, td = q[h].d;
        h ++;
        for ( int i = 0; i < 4; i ++ ) {
            int nx = tx + dx[i], ny = ty + dy[i];
            if ( nx > 0 && nx <= m && ny > 0 && ny <= n && !g[nx][ny] ) {
                if ( nx == m && ny == n ) {
                    printf("%d\n", td + 1);
                    return 0;
                } else {
                    t ++;
                    q[t].x = nx;
                    q[t].y = ny;
                    q[t].d = td + 1;
                    g[nx][ny] = true;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
