#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, maxn = -0x7fffffff, x = 0;
    scanf("%d", &n);
    vector< pair<int, int> > p(n);
    for ( int i = 0; i < n; i++ )
        scanf("%d%d", &p[i].first, &p[i].second);
    sort( p.begin(), p.end() );
    for ( auto i : p )
        x += i.first > maxn, maxn = ( i.first <= maxn ) ? ( maxn > i.second ? maxn : i.second ) : i.second;
    printf("%d\n", x);
    return 0;
}
