#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int L = 53;
const char a[] = "DFS", b[] = "dfs";
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    while ( n -- ) {
        int v, m = 0, n = 0;
        char s[L];
        scanf("%d%s", &v, s);
        for ( int i = 0; i < v; i ++ ) {
            if ( m < 3 && s[i] == a[m] )
                m ++;
            if ( n < 3 && s[i] == b[n] )
                n ++;
        }
        printf("%d %d\n", m / 3, n / 3);
    }
    return 0;
}
