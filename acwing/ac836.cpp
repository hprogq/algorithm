#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;

int find( int p[N], int x ) {
    if ( p[x] != x )
        p[x] = find(p, p[x]);
    return p[x];
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    scanf("%d %d\n", &n, &m);
    int p[N] = { 0 };
    for ( int i = 1; i <= n; i ++ )
        p[i] = i;
    while ( m -- ) {
        char op;
        int a, b;
        scanf("%c %d %d\n", &op, &a, &b);
        if ( op == 'M' )
            p[ find(p, a) ] = find(p, b);
        else if ( op == 'Q' ) {
            if ( find(p, a) == find(p, b) )
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
