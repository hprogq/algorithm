#include <stdio.h>
int main(void) {
    for ( ; ; ) {
        int n, m;
        scanf ("%d %d", &n, &m);
        if ( n == 0 && m == 0 )
            break;
        long double ans = 0.0;
        for ( int i = n; i <= m; i++ )
            ans += 1.0 / i / i;
        printf("%.5Lf\n", ans);
    }
    return 0;
}
