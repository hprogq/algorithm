#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> dot;
typedef long double LD;
const LD PI = 3.14159265;

int main() {
    LD ans = 0;
    int n, x1, x2, y1, y2;
    scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
    vector<dot> d(n);
    for ( int i = 0; i < n; i ++ )
        scanf("%d%d", &d[i].first, &d[i].second);
    sort( d.begin(), d.end() );
    do {
        long double s = 0;
        vector<LD> l(n);
        for ( int i = 0; i < n; i ++ ) {
            auto [ x, y ] = d[i];
            LD m = min( min( abs( x - x1 ), abs( x - x2 ) ), min( abs( y - y1 ), abs( y - y2 ) ) );
            for ( int j = 0; j < i; j ++ ) {
                LD b = sqrt( (LD) pow( d[j].first - x, 2 ) + (LD) pow( d[j].second - y, 2 ) ) - l[j];
                if ( b <= 0 ) {
                    m = 0;
                    break;
                } else m = min( m, b );
            }
            l[i] = m, s += PI * m * m;
        }
        ans = max( ans, s );
    } while ( next_permutation( d.begin(), d.end() ) );
    printf("%d\n", (int) round( abs( x1 - x2 ) * abs( y1 - y2 ) - ans ));
    return 0;
}
