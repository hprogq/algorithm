#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e8 + 10;
int main() {
    bool t[N] = { false };
    int a[N], n;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d", &a[i]);
        t[ abs( a[i] - a[ i - 1 ] ) ] = true;
    }
    int flag = true;
    for ( int i = 1; i <= n - 1; i++ )
        if ( !t[i] ) {
            flag = false;
            break;
        }
    if ( flag )
        printf("Jolly");
    else printf("Not jolly");
    return 0;
}
