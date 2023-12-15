#include <iostream>
#include <cstdio>
#define MAXN 10005
using namespace std;
int main() {
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int t, y1, y2, n;
    scanf("%d", &t);
    for ( int i = 1; i <= t; i++ ) {
        bool s[MAXN] = { false };
        scanf("%d%d", &y1, &n);
        for ( int j = 1; j <= n; j++ ) {
            int t;
            scanf("%d", &t);
            s[t] = true;
        }
        scanf("%d", &y2);
        int a = 0;
        for ( int j = y1; j <= y2; j++ )
            if ( !s[j] )
                a++;
        printf("%d\n", a);
    }
    return 0;
}
