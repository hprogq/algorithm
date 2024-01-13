// Acwing 95 / hprogq
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 5, A = 6;  // N：图的大小，A：最大步数

// 切换图g的(x, y)点
void change( bool g[N][N], int x, int y ) {
    g[x][y] = !g[x][y];  // 这是最简单的一种取反写法
    if ( x > 0 )  g[ x - 1 ][y] ^= 1;  // 对1进行异或，更简单
    if ( y > 0 )  g[x][ y - 1 ] ^= 1;
    if ( x + 1 < N )  g[ x + 1 ][y] ^= 1;
    if ( y + 1 < N )  g[x][ y + 1 ] ^= 1;
    return;
}

// 判断图g是否已经全开
bool check( bool g[N][N] ) {
    for ( int i = 0; i < N; i ++ )
        for ( int j = 0; j < N; j ++ )
            if ( !g[i][j] )
                return false;
    return true;
}

// 递归，图g处理到了第r行，目前已经花费n步
int solve( bool g[N][N], int s, int r ) {
    // 停止条件
    if ( s > A )  return -1;  // 只要步数超了就应该结束，返回-1
    if ( check(g) )  return s;  // 符合题意了，提前成功，返回步数
    if ( r >= N )  return -1;  // 到最后了也没成功，返回-1
    // 如果是第一行，即0行
    if ( !r ) {
        int ans = -1;  // 初始值
        for ( int i = 0; i <= 1 << N; i ++ ) {  // 从0到2的N次方的二进制 枚举5位状态
            int d = 0;  // 步数，先给0
            bool b[N][N];  // 图的备份（backup）
            memcpy( b, g, sizeof(bool) * N * N );  // 对当前的图进行备份，注意大小
            for ( int j = 0, k = i; j < N; j ++ ) {  // 从第1位枚举到第N位，避免改i
                if ( k & 1 ) {  // 判断该位是否为真，即改变这盏灯
                    d ++;  // 这个状态下的步数+1
                    change( g, r, j );  // 切换这盏灯和周边的状态
                }
                k >>= 1;  // 准备下一位
            }
            int tmp = solve( g, s + d, r + 1 );  // 递归并获取往后走的结果
            if ( ~tmp && tmp <= ( ~ans ? ans : A ) )  // 若ans有值就判断谁小否则存
                ans = tmp;
            memcpy( g, b, sizeof(bool) * N * N );  // 恢复备份
        }
        return ans;  // 返回最终的最小步数
    } else {  // 第2到N行，这里的备份是没有必要的，因为路径是唯一的
        int d = 0;  // 第一行确定了怎么切换之后，如果想成功则以后每一行的方案都是固定的了
        // bool b[N][N];  // 备份，其实没有必要
        // memcpy( b, g, sizeof(bool) * N * N );  // 同上
        for ( int i = 0; i < N; i ++ )  // 枚举这一行的上面一行的每一列
            if ( !g[ r - 1 ][i] ) {  // 上面一行的这一列还是关着的
                d ++;  // 步数+1
                change( g, r, i );  // 想让它亮，那只能通过切换它下面的这盏灯了
            }
        int tmp = solve( g, s + d, r + 1 );  // 接着往后走，直到边界条件
        // memcpy( g, b, sizeof(bool) * N * N );  // 恢复备份（其实没有必要）
        return tmp;  // 返回递归结果，和上一句可以合并
    }
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        bool g[N][N];  // 用来存图（graph）
        for ( int i = 0; i < N; i ++ ) {
            int t, m = N;
            scanf("%d", &t);  // 以整型读入，其实也可以以字符型读，不过这样更安全
            while ( m -- )  // 从后往前读，递推更好写一些
                g[i][m] = t % 10, t /= 10;  // 取最后一位并存入，然后去掉最后一位
        }
        printf("%d\n", solve( g, 0, 0 ));  // 直接输出就行，结果不存在的情况已经写了
    }
    return 0;
}
