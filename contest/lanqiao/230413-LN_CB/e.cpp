#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int N = 1e5 + 10;

int maxn = 0, xa, xb, xc;
int getlcm( int a, int b, int c ) {
	return __gcd( __gcd( a, b ), c );
}

int main() {
#ifdef LOCAL
	freopen("temp.in", "r", stdin);
	// freopen("temp.out", "w", stdout);
#endif
	int n, x[N];
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ )
		scanf("%d", &x[i]);
	for ( int i = 1; i <= n; i ++ )
		for ( int j = i + 1; j <= n; j ++ )
			for ( int k = j + 1; k <= n; k ++ ) {
				int t = getlcm( x[i], x[j], x[k] );
				if ( t > maxn ) {
					maxn = t;
					xa = i, xb = j, xc = k;
				}
			}
	printf("%d %d %d\n", xa, xb, xc);
	return 0;
}

