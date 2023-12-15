#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    long long d;
    scanf("%lld", &d);
    long long minn = 2e13;
    for ( long long x = 0; x <= sqrt( d / 2 ); x ++ ) {
        long long y1 = sqrt( d - x * x );
        long long y2 = y1 + 1;
        minn = min( minn, min( abs( x * x + y1 * y1 - d ), abs( x * x + y2 * y2 - d ) ) );
    }
    printf("%lld\n", minn);
    return 0;
}
