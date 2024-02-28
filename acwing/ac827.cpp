#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int val[N], ln[N] = {0}, rn[N] = {0}; // val: 存储键值，ln、rn分别指向某键左、右两侧的元素。
    int idx = 0, l = 0, r = 0, n = 0; // idx: 当前已存位置指针，l: 最左端指针，r: 最右端指针，n: 当前链表中元素个数。存放下标从1开始。
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        char op[3];
        scanf("%s", op);
        if ( *op == 'L' ) {
            scanf("%d", &val[++idx]); // 指针右移，读入值。
            ln[idx] = 0; // 成为表头
            rn[idx] = l; // 连接原表头
            l = ln[l] = idx; // 也是连接原表头，再改变表头指针
            r = ++n == 1 ? idx : r; // 仅剩一个元素要更新表尾指针
        } else if ( *op == 'R' ) { // 同理
            scanf("%d", &val[++idx]);
            rn[idx] = 0;
            ln[idx] = r;
            r = rn[r] = idx;
            l = ++n == 1 ? idx : l;
        } else if ( *op == 'D' ) {
            int k;
            scanf("%d", &k);
            if ( l == k )
                l = rn[k]; // 更新表头指针
            if ( r == k )
                r = ln[k]; // 更新表尾指针
            rn[ln[k]] = rn[k]; // 断开左侧元素
            ln[rn[k]] = ln[k]; // 断开右侧元素
            n --;
        } else if ( op[0] == 'I' && op[1] == 'L' ) {
            int k;
            scanf("%d%d", &k, &val[++idx]); // 同上
            if ( l == k )
                l = idx; // 在头部插入时，更新左值
            ln[idx] = ln[k]; // 连接k左侧元素
            rn[idx] = k; // 右侧连接k
            rn[ln[k]] = idx; // 还是连接k左侧元素
            ln[k] = idx; // 还是右侧连接k 注意上方几条语句的执行顺序
            n ++;
        } else if ( op[0] == 'I' && op[1] == 'R' ) { // 同理
            int k;
            scanf("%d%d", &k, &val[++idx]);
            if ( r == k )
                r = idx;
            rn[idx] = rn[k];
            ln[idx] = k;
            ln[rn[k]] = idx;
            rn[k] = idx;
            n ++;
        }
    }
    for ( int i = l; i; i = rn[i] ) // 由于idx是从1开始存储的，则遇到0就可以停止了。
        printf("%d ", val[i]); // 上面的语句可能会影响ln[0]、rn[0]，但是不会影响这里的语句（当i为0循环就停止了）
    return 0;
}
