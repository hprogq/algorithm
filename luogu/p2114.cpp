#include <cstdio>
using namespace std;
const int N = 1e5 + 10;

int cal( char op, int a, int b ) {
    switch( op ) {
        case 'O': return a | b;
        case 'X': return a ^ b;
        case 'A': return a & b;
    }
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m, t[N], a = 0;
    char op[N][3];
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++ )
        scanf("%s%d", op[i], &t[i]);
    for ( int i = 29; ~i; i -- ) {
        int x = 1, y = 0;
        for ( int j = 1; j <= n; j ++ )
            x = cal( *op[j], x, t[j] >> i & 1 ), y = cal( *op[j], y, t[j] >> i & 1 );
        if ( y || ( x && 1 << i <= m ) )  a |= 1 << i, m -= !y << i;
    }
    printf("%d\n", a);
    return 0;
}
