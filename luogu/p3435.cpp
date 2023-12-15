// 如果前缀 [1 ... i] 有一个公共前后缀，其长度为j，那么这个前缀就有一个周期为[ 1 ... i - j ].
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int main() {
#ifdef LOCAL
    freopen("p3435.in", "r", stdin);
    freopen("p3435.out", "w", stdout);
#endif
    char s[N];
    int l;
    unsigned long long ans = 0;
    scanf("%d\n", &l);
    scanf("%s", s + 1);
    int ne[N] = { 0 };
    for ( int i = 2, j = 0; i <= l; i ++ ) {
        while ( j && s[i] != s[ j + 1 ] )  j = ne[j];
        if ( s[i] == s[ j + 1 ] )  j ++;
        ne[i] = j;
    }
    for ( int i = 2, j = 2; i <= l; j = ++ i ) {
        while ( ne[j] )
            j = ne[j];
        if ( ne[i] )  ne[i] = j;
        ans += i - j;
    }
    printf("%llu\n", ans);
    return 0;
}