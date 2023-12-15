#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, m[N] = { 0 }, maxl = 0, l = 0, r = 0;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        int t;
        scanf("%d", &t);
        l = m[t] > l ? m[t] : l;
        m[t] = i;
        maxl = max( ++r - l, maxl );
    }
    printf("%d\n", maxl);
    return 0;
}
