#include <iostream>
using namespace std;
const int N = 1e5 + 10;
void quick_sort(int u[], int l, int r) {
    if ( l >= r )
        return;
    
    int x = u[ ( l + r ) >> 1 ];
    int i = l - 1, j = r + 1;
    
    while ( i < j ) {
        do i++; while ( u[i] < x );
        do j--; while ( u[j] > x );
        if ( i < j )  swap( u[i], u[j] );
    }
    
    quick_sort(u, l, j);
    quick_sort(u, j + 1, r);
    return;
}
int main() {
    int n, u[N], k;
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &u[i]);
    quick_sort(u, 1, n);
    printf("%d\n", u[k]);
    return 0;
}
