#include <iostream>
using namespace std;
const int N = 1e5 + 10;
char op[2];
int n, m, p[N], a, b;

int find( int x ) {
    if ( p[x] != x )
        p[x] = find( p[x] );
    return p[x];
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++ )
        p[i] = i;
    while ( m -- ) {
        scanf("%s%d%d", op, &a, &b);
        if ( *op == 'M' )
            p[ find(a) ] = find(b);
        else if ( *op == 'Q' )
            puts( find(a) == find(b) ? "Yes" : "No" );
    }
    return 0;
}
