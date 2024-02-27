#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, q, a[N];
    scanf("%d%d", &n, &q);
    for ( int i = 0; i < n; i ++ )
        scanf("%d", &a[i]);
    while ( q -- ) {
        int x;
        scanf("%d", &x);
        // 注意二分前提：数组有序（题中已给出）。
        int l = 0, r = n - 1; // 左端点、右端点。
        // 找左值部分，边界条件是l与r相等（即确定唯一点）。
        while ( l != r ) {
            int mid = ( l + r ) >> 1; // 取中间值
            if ( a[mid] >= x ) // 若中间值大于等于被询问数，则所求左值一定在mid左侧。
                r = mid; // 将右端点调整为mid
            else l = mid + 1; // 同理
        }
        // 若无法找到被询问值则直接输出两个-1即可。
        if ( a[l] != x ) {
            printf("-1 -1\n");
            continue; // 继续下一个询问
        } else printf("%d ", l); // 否则输出左值
        l = 0, r = n - 1; // 重要：在开始寻找右值之前，记得重置！
        while ( l != r ) {
            int mid = ( l + r + 1 ) >> 1; // 避免二分只有两个数时l或r不变进入死循环。
            if ( a[mid] <= x )
                l = mid;
            else r = mid - 1;
            // 上面两行的l右侧和r左侧共同组成了一个完整的坐标轴。可以这么记忆。
        }
        printf("%d\n", l); // l和r是一样的。
    }
    return 0;
}
