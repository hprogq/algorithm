#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int g[N];
int main() {
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int n;
        scanf("%d", &n);
        for ( int i = 0; i < n; i ++ )
            scanf("%d", &g[i]);
        sort(g, g + n);
        long long ans = 0;
        for ( int i = 0; i < n; i ++ )
            ans += g[i] * i;
        printf("%lld\n", 4 * ans);
    }
    return 0;
}
