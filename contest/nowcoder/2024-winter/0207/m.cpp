// 卡了一个小时，卡在数据范围上了。注意两个int相加在这道题的数据范围下会溢出。
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pir;
typedef long long ll;
const int d[2][5] = {
    { 0, 2, 4, 6, 8 },
    { 1, 3, 5, 7, 9 }
};
int sumx(ll x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
const int N = 2e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    ll ans = 0;
    scanf("%d", &n);
    int modd[2][9] = {0}, endd[10][9] = {0}, sing[10] = {0};
    for ( int i = 1; i <= n; i ++ ) {
        ll t;
        scanf("%lld", &t);
        int summ = sumx(t) % 9;
        modd[ (t < 10 || ( t % 100 ) % 4) ? 1 : 0 ][ summ ] ++;
        endd[ t % 10 ][ summ ] ++;
        if ( t < 10 )
            sing[t] ++;
    }
    for ( int i = 1; i <= 8; i ++ ) {
        int j = 9 - i;
        ans += 1LL * ( modd[0][j] + modd[1][j] ) * modd[0][i];
    }
    if ( modd[0][0] )
        ans += 1LL * modd[0][0] * ( modd[0][0] + modd[1][0] - 1 );
    for ( int i = 0; i < 9; i += 2 )
        for ( int j = 0; j < 5; j ++ )
            ans += 1LL * endd[ d[i % 4 ? 1 : 0][j] ][9 - i] * sing[i];
    printf("%lld\n", ans);
    return 0;
}
