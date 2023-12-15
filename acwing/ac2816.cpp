#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, m, a[N], b[N], x = 1, y = 1;
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i <= m; i++ )
        scanf("%d", &b[i]);
    while ( x <= n ) {
        while ( y <= m && a[x] != b[y] )  y++;
        if ( y > m ) {
            printf("No\n");
            return 0;
        }
        x++, y++;
    }
    printf("Yes\n");
    return 0;
}
