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
    int p[N] = { 0 }, cnt[N] = { 0 };
    for ( int i = 1; i <= n; i ++ ) {
        p[i] = i;
        cnt[i] ++;
    }
    while ( m -- ) {
        char op[2];
        int a, b;
        scanf("%s %d", op, &a);
        if ( op[0] == 'C' ) {
            scanf(" %d\n", &b);
            p[ find(p, a) ] = find(p, b);
            cnt[ find(p, b) ] += cnt[ find(p, a) ], cnt[ find(p, a) ] = 0;
        } else if ( op[0] == 'Q' && op[1] == '1' ) {
            scanf(" %d\n", &b);
            printf( find(p, a) == find(p, b) ? "Yes\n" : "No\n");
        } else if ( op[0] == 'Q' && op[1] == '2' ) {
            getchar();
            printf("%d\n", cnt[ find(p, a) ]);
        }
    }
    return 0;
}
