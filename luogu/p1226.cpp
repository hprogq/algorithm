#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
int main() {
    LL a, b, p, s = 1;
    scanf("%lld%lld%lld", &a, &b, &p);
    for ( LL x = b, t = a % p; x; x >>= 1, t = t * t % p ) if ( x & 1 ) {
        s = s * t % p;
    }
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, s);
    return 0;
}
