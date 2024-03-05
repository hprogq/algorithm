#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, k, h[N], w[N], maxn = 0;

int cut( int l ) {
    int res = 0;
    for ( int i = 1; i <= n; i ++ )
        res += ( h[i] / l ) * ( w[i] / l ); // 挨个巧克力分，统计一共能分出来几块。
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d%d", &h[i], &w[i]);
        maxn = max( maxn, max( h[i], w[i] ) ); // 求maxn是为了得到二分范围的右端点。
    }
    int l = 1, r = maxn;
    while ( l != r ) {
        int mid = ( l + r + 1 ) >> 1;
        if ( cut(mid) >= k ) // 现在能切出来大于等于k份（够分）的话
            l = mid; // 看看还不能再切大点
        else r = mid - 1; // 否则就切小点吧
    }
    printf("%d\n", l);
    return 0;
}
