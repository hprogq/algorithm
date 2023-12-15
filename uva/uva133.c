#include <stdio.h>
#include <string.h>
#define MAXN 21
#define FLAG -1
int n, k, m, stat[MAXN] = {0};
int go( int ind, int num, int dist, int direct) {
    if ( num == n )
        dist--;
    while ( dist ) {
        int temp = ( ind + direct ) % n;
        ind = temp ? temp : n;
        if ( !stat[ind] )
            dist--;
    }
    return ind;
}
int main( void ) {
#ifdef LOCAL
    freopen("uva133.in", "r", stdin);
    freopen("uva133.out", "w", stdout);
#endif
    while ( ~scanf("%d %d %d", &n, &k, &m) && n != 0 ) {
        int ind_a = 1, ind_b = n;
        memset(stat, 0, sizeof(stat));
        int left = n;
        while ( left ) {
            ind_a = go(ind_a, left, k, 1);
            ind_b = go(ind_b, left, m, -1);
            stat[ind_a] = FLAG;
            stat[ind_b] = FLAG;
            if ( ind_a == ind_b ) {
                printf("%3d", ind_a);
                left--;
            } else {
                printf("%3d%3d", ind_a, ind_b);
                left -= 2;
            }
            if ( left )
                printf(",");
            else printf("\n");
        }
    }
    return 0;
}
