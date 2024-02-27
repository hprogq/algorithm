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
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int n;
        int x, y, z, k[4][4];
        memset(k, -1, sizeof(int) * 16);
        scanf("%d", &n);
        if ( n == 1 ) {
            scanf("%d%d%d", &x, &y, &z);
            if ( x == y && z != 0 )
                printf("No\n");
            else printf("Yes\n");
        } else {
            scanf("%d%d%d", &x, &y, &z);
            if ( x == y && z != 0 ) {
                printf("No\n");
                scanf("%d%d%d", &x, &y, &z);
                continue;
            }
            k[x][y] = z;
            scanf("%d%d%d", &x, &y, &z);
            if ( x == y && z != 0 )
                printf("No\n");
            else if ( ~k[x][y] && k[x][y] != z ) {
                printf("No\n");
            } else if ( x != y && ~k[y][x] && k[y][x] == 1 && z == 1 ) {
                printf("No\n");
            } else printf("Yes\n");
        }
    }
    return 0;
}
