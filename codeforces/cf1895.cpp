#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while ( n-- ) {
        int x, y, k;  // x: key, y: box
        scanf("%d%d%d", &x, &y, &k);
        if ( x >= y )
            printf("%d\n", x);
        else if ( k >= y - x )
            printf("%d\n", y);
        else printf("%d\n", 2 * y - x - k);
    }
    return 0;
}