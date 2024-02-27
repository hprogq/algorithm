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
const int N = 2e5 + 10;
int con( int a, int b ) {
    return a * ( a == 10 ? 100 : 10 ) + b;
}
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, ans = 0;
    scanf("%d", &n);
    int a[N];
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= n; j ++ )
            if ( i != j && con(a[i], a[j]) % 36 == 0 )
                ans ++;
    printf("%d\n", ans);
    return 0;
}
