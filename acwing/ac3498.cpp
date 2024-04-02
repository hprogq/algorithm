#include <iostream>
#include <cmath>
using namespace std;

const int ds[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

bool ry( int y ) {
    return !( y % 4 ) && ( y % 100 || !( y % 400 ) );
}

long long ts( int x ) {
    long long t = 0;
    int y = x / 10000,
        m = x / 100 % 100,
        d = x % 100;
    for ( int i = 1; i <= y - 1; i ++ )
        t += ry(i) ? 366 : 365;
    for ( int i = 1; i <= m - 1; i ++ )
        t += ds[ ry(y) ][i];
    return t + d;
}

using namespace std;
int main() {
    int a, b;
    while ( ~scanf("%d%d", &a, &b) )
        printf("%lld\n", abs( ts(a) - ts(b) ) + 1);
    return 0;
}
