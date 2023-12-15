#include <iostream>
using namespace std;
const int N = 5e6 + 10;

void merge_sort( int u[], int l, int r ) {
    if ( l >= r )
        return;

    int mid = ( l + r ) >> 1;
    
    merge_sort( u, l, mid );
    merge_sort( u, mid + 1, r );
    
    int i = l, j = mid + 1, k = 0, c[N];
    
    while ( i <= mid && j <= r )
        if ( u[i] < u[j] )
            c[ k++ ] = u[ i++ ];
        else c[ k++ ] = u[ j++ ];
    
    while ( i <= mid )
        c[ k++ ] = u[ i++ ];
    
    while ( j <= r )
        c[ k++ ] = u[ j++ ];
        
    for ( int i = l, j = 0; i <= r; i++, j++ )
        u[i] = c[j];
    
    return;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int u[N];
    for ( int i = 0; i < n; i++ )
        scanf("%d", &u[i]);
    merge_sort( u, 0, n - 1 );
    printf("%d\n", u[q]);
    return 0;
}
