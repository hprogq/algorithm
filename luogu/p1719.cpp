#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 180;
int main() {
    int n, a[N][N], s[N][N];
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ ) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[ i - 1 ][j] + s[i][ j - 1 ] - s[ i - 1 ][ j - 1 ] + a[i][j];
        }
    int maxn = -0xffffffff;
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
            for ( int k = i; k <= n; k++ )
                for ( int l = j; l <= n; l++ )
                    maxn = max( maxn, s[k][l] - s[i-1][l] - s[k][j-1] + s[i-1][j-1] );
    printf("%d\n", maxn);
    return 0;
}
