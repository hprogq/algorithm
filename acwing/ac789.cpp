#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, kase, u[N];
    scanf("%d%d", &n, &kase);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &u[i]);
    while ( kase-- ) {
        int x;
        scanf("%d", &x);
        
        int l = 0, r = n - 1;
        while ( l != r ) {
            int mid = ( l + r ) >> 1;
            if ( u[mid] >= x )  r = mid;
            else l = mid + 1;
        }
        
        if ( u[r] != x )  printf("-1 -1\n");
        else {
            printf("%d ", l);
            l = 0, r = n - 1;
            
            while ( l != r ) {
                int mid = ( l + r + 1 ) >> 1;
                if ( u[mid] <= x )  l = mid;
                else r = mid - 1;
            }
            
            printf("%d\n", r);
        }
    }
    return 0;
}
