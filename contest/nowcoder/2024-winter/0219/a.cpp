#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 10;

void move( char g[N][N], int n, int m, int op, int z ) {
    if ( op == 1 ) {
        char t = g[z][m];
        for ( int i = m; i >= 2; i -- )
            g[z][i] = g[z][ i - 1 ];
        g[z][1] = t;
    } else if ( op == 2 ) {
        char t = g[n][z];
        for ( int i = n; i >= 2; i -- )
            g[i][z] = g[ i - 1 ][z];
        g[1][z] = t;
    }
    return;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m, x, y;
    char g[N][N] = {0};
    scanf("%d %d %d %d\n", &n, &m, &x, &y);
    for ( int i = 1; i <= n; i ++ ) {
        char t[N];
        scanf("%s", t + 1);
        for ( int j = 1; j <= m; j ++ )
            g[i][j] = t[j];
    }
    int p, q;
    scanf("%d%d", &p, &q);
    while ( q -- ) {
        int op, z;
        scanf("%d%d", &op, &z);
        move(g, n, m, op, z);
    }
    printf("%c", g[x][y]);
    return 0;
}