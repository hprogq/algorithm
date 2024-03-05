#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int n, m, r[N], d[N], s[N], t[N]; // rdst的作用均如题目所述，其实换成l、r会更好。
long long x[N]; // 存差分的数组，最后用前缀和累加。

int check( int e ) { // 二分，判断是否能满足前e份订单。
    memset(x, 0, sizeof x); // sizeof加不加括号都可以哦。避免反复请求空间，直接进行清空操作会更快。
    for ( int i = 1; i <= e; i ++ )
        x[ s[i] ] += d[i], x[ t[i] + 1 ] -= d[i]; // 差分，给s到t的每一天都加上d。
    for ( int i = 1; i <= n; i ++ ) { // 前缀和累加，并同时检测每天的教室是否足够。
        x[i] += x[ i - 1 ]; // 累加。注意这里累加后结果x的实际意义是第i天被租借的总教室数量。
        if ( x[i] > r[i] ) // 超出了。
            return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &r[i]);
    for ( int i = 1; i <= m; i ++ )
        scanf("%d%d%d", &d[i], &s[i], &t[i]);
    
    int l = 0, r = m;
    while ( l != r ) { // 二分。注意这里的两段性是天数越小时越容易满足条件。
        int mid = ( l + r + 1 ) >> 1;
        if ( check(mid) )
            l = mid; // 还行，没超，可以再多两天试试。
        else r = mid - 1; // mid点租借多了，那天数应该再少点。
    }
    // 需要理解上方二分语句的结果（lower_bound）。
    // l和r最后拿到的值是“最多能满足多少天的订单”。
    // 题目所求的是“从哪天开始不满足了”。
    if ( r != m )
        printf("-1\n%d\n", r + 1);
    else printf("0\n");
    return 0;

}