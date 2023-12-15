#include <iostream>
using namespace std;
const int N = 5e4 + 10;

int find( int p[N], int x ) {
    if ( p[x] != 0 && p[x] != x )
        p[x] = find( p, p[x] );
    return p[x];
}

int main() {
    int n, k, p[N] = { 0 }, real = 1, fake = 0, idx = 1, t[4];
    scanf("%d%d", &n, &k);
    while ( k --  ) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if ( x > n || y > n ) {
            fake ++;
            continue;
        }
        if ( op == 1 ) { // combine
            if ( x == y )
                continue;
        } else if ( op == 2 ) { // eat
            // 0 0
            if ( !find( p, p[x] ) && !find( p, p[y] ) ) {
                p[x] = x;
                p[y] = x;
            } else if ( !find( p, p[x] ) && !find( p, p[y] ) )
        }
    }
    return 0;
}
