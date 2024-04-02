#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e4 + 10;
int main() {
    int w, n, a[N], ans = 0;
    scanf("%d%d", &w, &n);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    int l = 1, r = n;
    sort( a + 1, a + n + 1 );
    while ( l < r && a[l] <= w ) {
        while ( l <= r && a[l] + a[r] > w )
            r --, ans ++;
        if ( l != r && a[l] + a[r] <= w )
            l ++, r --, ans ++;
    }
    while ( l <= r )
        l ++, ans ++;
    printf("%d\n", ans);
    return 0;
}
