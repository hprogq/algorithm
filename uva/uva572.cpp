#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 120;
const char F = '@';

void dfs( bool (&pic)[N][N], bool (&vis)[N][N], int x, int y, int r, int c ) {
    vis[x][y] = true;
    for ( int i = -1; i <= 1; i++ )
        for ( int j = -1; j <= 1; j++ )
            if ( !( i == 0 && j == 0 ) && x + i >= 0 && y + j >= 0 && x + i < r && y + j < c && pic[ x + i ][ y + j ] && !vis[ x + i ][ y + j ] )
                dfs( pic, vis, x + i, y + j, r, c );
    return;
}

int main() {
#ifdef LOCAL
    freopen("uva572.in", "r", stdin);
    freopen("uva572.out", "w", stdout);
#endif
    int r, c;
    while ( ~scanf("%d %d\n", &r, &c) && r && c ) {
        int x = 0;
        bool pic[N][N] = { false }, vis[N][N] = { false };
        for ( int i = 0; i < r; i++ ) {
            string s;
            getline(cin, s);
            for ( int j = 0; j < c; j++ )
                pic[i][j] = s[j] == F ? true : false;
        }
        for ( int i = 0; i < r; i++ )
            for ( int j = 0; j < c; j++ )
                if ( pic[i][j] && !vis[i][j] )
                    x++, dfs( pic, vis, i, j, r, c );
        printf("%d\n", x);
    }
    return 0;
}
