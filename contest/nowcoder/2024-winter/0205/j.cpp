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
        long long ans = 0;
        scanf("%d", &n);
        for ( int i = 0; i < n; i ++ )
            scanf("%d", &g[i]);
        sort(g, g + n);
        int lesx = 0;
        for ( int i = 0; i < n && g[i] < g[0] * 2; i ++ ) {
            ans += 2 * ( n - i - 1 ) * g[i];
            lesx ++;
        }
        ans += ( n - lesx ) * ( n - lesx - 1 ) * 2 * g[0];
        printf("%lld\n", 2 * ans);
    }
    return 0;
}
