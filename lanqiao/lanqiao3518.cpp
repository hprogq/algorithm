#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int get( int n, int a[], int b[], int c[] ) {
    int d[N], k = 0;
    long long sum = 0;
    for ( int i = 1; i <= n; i ++ )
        d[i] = a[i] - b[i] - c[i];
    sort( d + 1, d + n + 1, greater<int>() );
    while ( k <= n && ( !k || sum > 0 ) )
        sum += d[ ++ k ];
    return k - 1 ? k - 1 : -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[N], b[N], c[N];
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &b[i]);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &c[i]);
    printf("%d\n", max( max( get( n, a, b, c ), get( n, b, a, c ) ), get( n, c, a, b ) ));
    return 0;
}
