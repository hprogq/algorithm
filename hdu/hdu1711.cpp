#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXM = 4e5 + 10;
int main() {
#ifdef LOCAL
    freopen("hdu1711.in", "r", stdin);
    freopen("hdu1711.out", "w", stdout);
#endif
    char b[MAXM];
    while ( ~scanf("%s", b + 1) ) {
        int n, ne[MAXM];
        if ( b[1] == '.' )  return 0;
        n = strlen( b + 1 );
        b[ n + 1 ] = '$';
        for ( int i = 2, j = 0; i <= n + 1; i ++ ) {
            while ( j && b[i] != b[ j + 1 ] )  j = ne[j];
            if ( b[i] == b[ j + 1 ] )  j++;
            ne[i] = j;
        }
        int x = n, k[MAXM], w = 0;
        k[ ++ w ] = n;
        while ( ne[x] )
            k[ ++ w ] = x = ne[x];
        for ( int i = w; i >= 1; i -- )
            printf("%d ", k[i]);
        printf("\n");
        
    }
    return 0;
}
