#include <iostream>
using namespace std;
const long double eps = 1e-8;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    long double n;
    scanf("%Lf", &n);
    long double l = -22, r = 22;
    while ( r - l > eps ) {
        long double mid = ( l + r ) / 2;
        if ( mid * mid * mid >= n )
            r = mid;
        else l = mid;
    }
    printf("%.6Lf", l);
    return 0;
}