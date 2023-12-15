#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> pir;
int main() {
    int n;
    pir a[N];
    scanf("%d", &n);
    long long sum = 0;
    a[0].first = INF, a[0].second = 0;
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        sum += a[i].first;
    }
    sort( a, a + n + 1 );
    bool lock = false;
    int last, idx = 0, l[N];
    long long w[N];
    for ( int i = 0; i <= n; i ++ ) {
        int t = a[i].first;
        if ( !lock ) {
            if ( t == INF )
                break;
            lock = true, last = t;
            l[ idx ++ ] = a[i].second;
            continue;
        }
        if ( t != last ) {
            sum -= last * idx;
            while ( idx -- )
                w[ l[idx] ] = sum;
            lock = false, idx = 0, i --;
            continue;
        }
        l[ idx ++ ] = a[i].second;
    }

    for ( int i = 1; i <= n; i ++ )
        printf("%lld ", w[i]);
    
    return 0;
}
