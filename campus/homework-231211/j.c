#include <stdio.h>
#define N 1000

int F( int x, int y, int z ) {
    return ( x + z ) / ( y - z ) + ( y + 2 * z ) / ( x - 2 * z );
}

int main() {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    printf("%d\n", F( x, y, z ));
    return 0;
}
