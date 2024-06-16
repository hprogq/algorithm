#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
const int D = 1100;
int d[D], len = 0;

void plust() {
	int ind = 0, t;
	for ( int i = 0; i < len; i ++ ) {
		t = d[i];
		d[i] = t * 2 % 10;
		d[i] += ind;
		ind = t * 2 / 10;
	}
	if ( ind )
		d[ len ++ ] = ind;
	return;
}

int main() {
#ifdef LOCAL
	freopen("temp.in", "r", stdin);
	// freopen("temp.out", "w", stdout);
#endif
	int n, dot = 0;
	char sd[D];
	scanf("%d%s", &n, sd);
	for ( int i = strlen(sd) - 1; i >= 0; i -- )
		if ( sd[i] != '.' )
			d[ len ++ ] = sd[i] - '0';
		else dot = dot ? dot : strlen(sd) - i - 1;
	while ( n -- )
		plust();
	for ( int i = len - 1; i >= dot; i -- )
		if ( i == dot && i != 0 )
			printf("%d", d[i] + ( d[ i - 1 ] >= 5 ? 1 : 0 ));
		else printf("%d", d[i]);
	return 0;
}

