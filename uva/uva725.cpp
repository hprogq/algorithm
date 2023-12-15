#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool test( int x, int y = 0 ) {
    bool t[10] = { false };
    while ( x < 10000 )
        x *= 10;
    while ( y && y < 10000 )
        y *= 10;
    while ( x ) {
        if ( t[ x % 10 ] )
            return false;
        t[ x % 10 ] = true;
        x /= 10;
    }
    while ( y ) {
        if ( t[ y % 10 ] )
            return false;
        t[ y % 10 ] = true;
        y /= 10;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    bool first = false;
    while ( ~scanf("%d", &n), n ) {
        if ( !first )
            first = true;
        else printf("\n");

        bool can = false;
        for ( int i = 1023; i <= 49876; i ++ )
            if ( test(i) && i * n <= 98765 && test( i, i * n ) ) {
                printf("%05d / %05d = %d\n", i * n, i, n);
                can = true;
            }
        if ( !can )
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}
