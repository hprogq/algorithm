#include <iostream>
using namespace std;

const int N = 1e5 + 10;

unsigned long long ans = 0;

void merge_sort(int u[], int l, int r) {
    if ( l >= r )
        return;
    
    int mid = ( l + r ) >> 1;
    merge_sort( u, l, mid );
    merge_sort( u, mid + 1, r );
    
    int t[N], k = 0, i = l, j = mid + 1;
    
    while ( i <= mid && j <= r )
        if ( u[i] <= u[j] )  t[ k++ ] = u[ i++ ];
        else t[ k++ ] = u[ j++ ], ans += mid - i + 1;
    
    while ( i <= mid )  t[ k++ ] = u[ i++ ];
    while ( j <= r )    t[ k++ ] = u[ j++ ];
    
    for ( int i = l, j = 0; i <= r; i++, j++ )
        u[i] = t[j];
    
    return;
}

int main() {
    int n, u[N];
    
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &u[i]);
    
    merge_sort(u, 1, n);
    
    printf("%lld\n", ans);
    
    return 0;
}
