#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pir;
int main() {
    int n, m;
    long long ans = 0;
    vector<pir> x;
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= m; i ++ ) {
        int a, b;
        scanf("%d%d", &a, &b);
        x.push_back( pir( a, b ) );
    }
    sort( x.begin(), x.end() );
    auto it = x.begin();
    while ( n && !x.empty() ) {
        int d = min( n, (*it).second );
        ans += ( long long ) d * (*it).first, n -= d;
        if ( n != d )
            it ++;
    }
    printf("%lld\n", ans);
    return 0;
}
