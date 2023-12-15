#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int main() {
    bool f = false;
    int n, l, r, p[N], minn = 0x3f3f3f3f, maxn = -1;
    scanf("%d%d%d", &n, &l, &r);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &p[i]);
    }
    for ( int i = 1; i <= n; i ++ ) {
        if ( p[i] >= l && p[i] <= r ) {
            printf("%d ", p[i]);
        } else if ( p[i] < l ) {
            printf("%d ", l);
        } else printf("%d ", r);
    }
    return 0;
}
