#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2023;

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, I[N] = { 0 }, J[N] = { 0 };
    bool G[N][N] = { false };
    string s;
    scanf("%d\n", &n);
    for ( int i = 1; i <= n; i ++ ) {
        getline( cin, s );
        for ( int j = 1; j <= n; j ++ ) {
            G[i][j] = ( s[ j - 1 ] == 'o' );
            if ( G[i][j] )
                I[i] ++, J[j] ++;
        }
    }
    long long sum = 0;
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= n; j ++ )
            if ( G[i][j] && I[i] >= 2 && J[j] >= 2 )
                sum += ( I[i] -1 ) * ( J[j] - 1 );
    printf("%lld\n", sum);
    return 0;
}
