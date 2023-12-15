#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n, s, m, l, minn = 0x3f3f3f3f;
    scanf("%d%d%d%d", &n, &s, &m, &l);
    for ( int i = 0; i <= ceil( 1.0 * n / 6 ); i ++ )
        for ( int j = 0; j <= ceil( 1.0 * n / 8 ); j ++ )
            for ( int k = 0; k <= ceil( 1.0 * n / 12 ); k ++ )
                if ( 6 * i + 8 * j + 12 * k >= n )
                    minn = min( minn, s * i + m * j + l * k );
    printf("%d\n", minn);
    return 0;
}
