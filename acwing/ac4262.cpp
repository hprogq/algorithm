#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, a[N], b[N] = {0}, t;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i ++ ) {
        scanf("%d", &t);
        a[i] -= t;
    }
    for ( int i = 1; i <= n; i ++ )
        b[i] = a[i] - a[ i - 1 ];
    int pos = 0, neg = 0;
    for ( int i = 1; i <= n; i ++ )
        if ( b[i] < 0 )
            neg += -b[i];
        else pos += b[i];
    printf("%d\n", max(neg, pos));
    return 0;
}
