#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    scanf("%lf", &x);
    
    if ( x < 0 ) {
        printf("-");
        x = -x;
    }

    double l = abs(x) < 1 ? x : 0, r = abs(x) < 1 ? 1 : x;
    
    while ( r - l > 1e-8 ) {
        double mid = ( l + r ) / 2;
        if ( mid * mid * mid > x )  r = mid;
        else l = mid;
    }
    
    printf("%lf\n", l);
    return 0;
}
