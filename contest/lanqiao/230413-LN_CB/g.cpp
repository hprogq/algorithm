#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;

typedef pair<int, int> pir;
typedef pair<pir, pir> status;

int n, p, q, h[N] = {0};
set< status, greater<status> > s;

void add( int delta, int method, int value, int id ) {
	s.insert( status( pir( delta, method ), pir( id, value ) ) );
}

void choose( int t, int id ) {
	h[id] = t;
	// printf("h[%d] = %d\n", id, t);
	int dp = t - (int) floor( sqrt(t) );
	int dq = t - t / 2;
	if ( dp > dq && p > 0 )
		add( dp, 0, t, id );
	else if ( q > 0 )
		add( dq, 1, t, id );
}

int main() {
#ifdef LOCAL
	freopen("temp.in", "r", stdin);
	// freopen("temp.out", "w", stdout);
#endif
	int t, ans = 0;
	scanf("%d%d%d", &n, &p, &q);
	for ( int i = 1; i <= n; i ++ ) {
		scanf("%d", &t);
		choose( t, i );
	}
	while ( ( p > 0 || q > 0) && !s.empty() ) {
		auto f = s.begin();
		int d = (*f).first.first;
		int m = (*f).first.second;
		int id = (*f).second.first;
		int x = (*f).second.second;
		if ( m == 0 ) {
			if ( p == 0 )
				choose( x, id );
			else {
				// cout << x - d << " " << id << endl;
				choose( x - d, id );
				p --;
			}
		} else if ( m == 1 ) {
			if ( q == 0 )
				choose( x, id );
			else {
				// cout << x - d << " " << id << endl;
				choose( x - d, id );
				q --;
			}
		}
		s.erase(f);
	}
	for ( int i = 1; i <= n; i ++ )
		ans += h[i];
	printf("%d\n", ans);
	return 0;
}

