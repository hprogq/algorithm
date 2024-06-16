#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

bool check( int n ) {
	int t = 0;
	while ( n ) {
		if ( ++ t % 2 ) {
			if ( n % 10 % 2 == 0 )
				return false;
		} else if ( n % 10 % 2 )
			return false;
		n /= 10;
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen("temp.in", "r", stdin);
	// freopen("temp.out", "w", stdout);
#endif
	int n, ans;
	scanf("%d", &n);
	for ( int i = 1; i <= n; i ++ )
		if ( check(i) )
			ans ++;
	printf("%d\n", ans);
	return 0;
}

