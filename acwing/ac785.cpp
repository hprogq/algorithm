#include <iostream>
using namespace std;
const int N = 1e6 + 10;

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
    int n, u[N];
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &u[i]);
    quick_sort(u, 0, n - 1);
    for ( int i = 0; i < n; i++ )
        printf("%d ", u[i]);
    return 0;
}
