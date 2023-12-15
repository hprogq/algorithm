#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("uva12657.in", "r", stdin);
    freopen("uva12657.out", "w", stdout);
#endif
    int n, m, kase = 0;
    while ( ~scanf("%d%d", &n, &m) ) {
        bool rev = false;
        vector<int> left( n + 2 ), right( n + 2 );

        for ( int i = 1; i <= n; i++ )
            left[i] = i - 1, right[i] = i + 1;
        left[0] = -1, right[0] = 1;
        left[ n + 1 ] = n, right[ n + 1 ] = -1;
        
        while ( m-- ) {
            int cmd, x, y;
            scanf("%d", &cmd);

            if ( cmd != 4 )
                scanf("%d%d", &x, &y);
            else rev = !rev;

            if ( cmd == 3 && left[x] != y && left[y] != x  )
                right[ left[x] ] = y, left[ right[x] ] = y, right[ left[y] ] = x, left[ right[y] ] = x, swap( left[x], left[y] ), swap( right[x], right[y] );
            else if ( cmd == 3 && left[x] == y )
                right[ left[y] ] = x, left[ right[x] ] = y, right[y] = right[x], left[x] = left[y], left[y] = x, right[x] = y;
            else if ( cmd == 3 && left[y] == x )
                right[ left[x] ] = y, left[ right[y] ] = x, right[x] = right[y], left[y] = left[x], left[x] = y, right[y] = x;
            else if ( cmd == ( rev ? 2 : 1 ) && left[y] != x )
                right[ left[x] ] = right[x], left[ right[x] ] = left[x], left[x] = left[y], right[x] = y, right[ left[y] ] = x, left[y] = x;
            else if ( cmd == ( rev ? 1 : 2 ) && right[y] != x )
                left[ right[x] ] = left[x], right[ left[x] ] = right[x], right[x] = right[y], left[x] = y, left[ right[y] ] = x, right[y] = x;
        }

        int t = rev ? n + 1 : 0, count = 0;
        long long int total = 0;
        if ( rev )
            while ( left[t] != -1 )
                t = left[t], total += ++count % 2 ? t : 0;
        else while ( right[t] != -1 )
                total += count++ % 2 ? t : 0, t = right[t];

        printf("Case %d: %lld\n", ++kase, total);
    }
    return 0;
}
