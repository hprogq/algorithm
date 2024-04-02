#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m = 0, x = 0, y = 0, l = 0;
    scanf("%d", &n);
    vector< pair<int, int> > p(n);
    for ( int i = 0; i < n; i++ )
        scanf("%d%d", &p[i].first, &p[i].second);
    sort(p.begin(), p.end());
    m = p[0].first;
    for ( auto i : p )
        if ( m < i.first )
            x = max(x, l), y = max(y, i.first - m), l = i.second - i.first, m = i.second;
        else l += max(0, i.second - m), m = max(m, i.second);
    printf("%d %d\n", max(x, l), y);
    return 0;
}
