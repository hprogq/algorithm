#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int c, d, h, w;
        scanf("%d%d%d%d", &c, &d, &h, &w);
        printf("%d\n", 3 * c * w);
    }
    return 0;
}
