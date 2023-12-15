#include <iostream>
using namespace std;
const int MAXN = 1e6 + 10;
int merge_sort(int u[], int l, int r) {
    if ( l >= r )
        return 0;
    
    int mid = ( l + r ) >> 1;
    int k1 = merge_sort(u, l, mid);
    int k2 = merge_sort(u, mid + 1, r);
    int tmp[MAXN], k = 0, i = l, j = mid + 1, s = 0;
    while ( i <= mid && j <= r )
        if ( u[i] <= u[j] )  tmp[ k++ ] = u[ i++ ];
        else s += mid + 1 - i, tmp[ k++ ] = u[ j++ ];
    
    while ( i <= mid )  tmp[ k++ ] = u[ i++ ];
    while ( j <= r )    tmp[ k++ ] = u[ j++ ];
    
    for ( int i = l, j = 0; i <= r; i++, j++ )
        u[i] = tmp[j];
    
    return s + k1 + k2;
}

int main() {
    int n, u[MAXN];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &u[i]);
    int x = merge_sort(u, 0, n-1);
    printf("%d\n", x);
    return 0;
}
