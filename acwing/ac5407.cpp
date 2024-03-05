#include <iostream>
#include <set>
using namespace std;
const int MAXS = 2e9;
typedef pair<int, int> pir;

bool check( set<pir> &st, int end, int len ) {
    set<pir> col; // 集合col存储在end时刻时每个阀门已覆盖的区间，自动升序排序。
    for ( pir e : st ) {
        if ( e.first > end )
            break;
        col.insert( pir( max( 0, e.second - ( end - e.first ) ), min( len, e.second + ( end - e.first ) ) ) );
    }
    pir range(0, 0); // 存储合并后的区间
    for ( pir e : col ) // 从前到后合并区间
        if ( e.first <= range.second + 1 ) // 如果发生了区间不连续的情况，则不可能符合条件（注意传感器有间隔、不连续，eg:[1,2][3,4]->[1,4]）
            range.second = max( range.second, e.second );
        else return false;
    if ( range.first == 0 && range.second == len ) // 如果覆盖满了整个管道
        return true;
    else return false;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, len;
    set<pir> st;
    scanf("%d%d", &n, &len);
    for ( int i = 1; i <= n; i ++ ) {
        int l, s;
        scanf("%d%d", &l, &s);
        st.insert( pir( s, l ) );
    }
    int l = 0, r = MAXS;
    // 本题需要注意到，阀门触发时间的数据范围也是1e9。
    // 同时，液体在最坏情况下（即从端点开始）覆盖满整个管道也需要约1e9的时间。
    // 则触发且覆盖完全的时刻的最大值会达到2e9，所以二分的范围需要从0到2e9，也即l和r的数据范围都是2e9。
    // 所以下面0LL的作用是为了进行强制类型转换，防止int类型的大整形l+r溢出导致结果错误。当然也可以通过定义l和r为long long实现。
    while ( l != r ) {
        int mid = ( 0LL + l + r ) >> 1;
        if ( check( st, mid, len ) )
            r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
    return 0;
}
