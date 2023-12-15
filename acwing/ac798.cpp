#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int a[N][N], b[N][N];

void insert( int lx, int ly, int rx, int ry, int c ) {
    b[lx][ly] += c;
    b[ rx + 1 ][ly] -= c;
    b[lx][ ry + 1 ] -= c;
    b[ rx + 1 ][ ry + 1 ] += c;
    return;
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ ) {
            int x;
            scanf("%d", &x);
            insert( i, j, i, j, x );
        }
    
    while ( q-- ) {
        int lx, ly, rx, ry, c;
        scanf("%d%d%d%d%d", &lx, &ly, &rx, &ry, &c);
        insert( lx, ly, rx, ry, c );
    }
    
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            a[i][j] = a[i][ j - 1 ] + a[ i - 1 ][j] - a[ i - 1 ][ j - 1 ] + b[i][j];
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    
    return 0;
}
