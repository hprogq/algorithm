#include <iostream>
#include <cstdio>
#include <cstring>

typedef unsigned long long ull;
const int N = 1e5 + 10, P = 131;

int get( int l, int r, ull h[], ull p[] ) {
    return h[r] - h[ l - 1 ] * p[ r - l + 1 ];
}

using namespace std;
int main() {
    int n, m;
    char s[N];
    scanf("%d%d%s", &n, &m, s + 1);
    ull h[N], p[N];
    p[0] = 1;
    for ( int i = 1; i <= n; i++ ) {
        h[i] = h[ i - 1 ] * P + s[i];
        p[i] = p[ i - 1 ] * P;
    }
    while ( m -- ) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if ( get( x1, y1, h, p ) == get( x2, y2, h, p ) )
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
