#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> dot;
typedef pair<dot, dot> line;
typedef set<line> route;
typedef pair<dot, route> path;
typedef pair<string, int> walk;
typedef pair<walk, path> status;
const int N = 15;
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 }, 
          dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int main() {
#ifdef LOCAL
	freopen("temp.in", "r", stdin);
	// freopen("temp.out", "w", stdout);
#endif
	int n, k, g[N][N];
	scanf("%d%d", &n, &k);
	for ( int i = 0; i < n; i ++ )
		for ( int j = 0; j < n; j ++ )
			scanf("%d", &g[i][j]);
	priority_queue<status> que;
	que.push( status( walk( string(), 0 ), path( dot(0, 0), route() ) ) );
	while ( !que.empty() ) {
		auto f = que.top();
		que.pop();
		string s = f.first.first;
		int num = f.first.second;
		dot x = f.second.first;
		route r = f.second.second;
		if ( x.first == n - 1 && x.second == n - 1 && r.size() == n * n - 1 ) {
			cout << r.size() << " " << s << endl;
			for ( auto e : r )
				printf("%d %d -> %d %d\n", e.first.first, e.first.second, e.second.first, e.second.second);
			return 0;
		}
		for ( int i = 0; i <= 7; i ++ ) {
			dot y( x.first + dx[i], x.second + dy[i] );
			if ( y.first >= 0 && y.first < n && y.second >= 0 && y.second < n && g[y.first][y.second] == ( g[x.first][x.second] + 1 ) % k && !r.count( line( dot( x.first, y.second ), dot( y.first, x.second ) ) ) && !r.count( line( dot( y.first, x.second ), dot( x.first, y.second ) ) ) ) {
				route newr = r;
				newr.insert( line( x, y ) );
				cout << g[x.first][x.second] << " ---> " << g[y.first][y.second] << endl;
				que.push( status( walk( s + (char) ( i + '0' ), g[y.first][y.second] ), path( y, newr ) ) );
			}
		}
	}
	cout << -1 << endl;
	return 0;
}

