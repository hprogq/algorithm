#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 200 + 10;

struct Node {
    int dist;
    int u[3];

    bool operator < ( const Node& r ) const {
        return dist > r.dist;
    }

    Node() {}
    Node( int d, int a, int b, int c ) : dist(d) {
        u[0] = a;
        u[1] = b;
        u[2] = c;
    }
};

void update( Node &x, int ans[N] ) {
    for ( int i = 0; i < 3; i ++ ) {
        int t = x.u[i];
        if ( !~ans[t] || x.dist < ans[t] )
            ans[t] = x.dist;
    }
    return;
}

void solve( int a, int b, int c, int d ) {
    bool vis[N][N] = { true, false };
    int cap[3] = { a, b, c }, ans[N];
    memset( ans, -1, sizeof(ans) );
    Node start( 0, 0, 0, c );
    priority_queue<Node> q;
    q.push(start);
    while ( !q.empty() ) {
        Node now = q.top();  q.pop();
        update( now, ans );
        if ( ans[d] >= 0 )
            break;
        for ( int i = 0; i < 3; i ++ )
            for ( int j = 0; j < 3; j ++ )
                if ( i != j && now.u[i] != 0 && now.u[j] != cap[j] ) {
                    int delta = min( cap[j], now.u[i] + now.u[j] ) - now.u[j];
                    Node temp;
                    temp.dist = now.dist + delta;
                    temp.u[i] = now.u[i] - delta;
                    temp.u[j] = now.u[j] + delta;
                    temp.u[ 3 - i - j ] = now.u[ 3 - i - j ];
                    if ( !vis[ temp.u[0] ][ temp.u[1] ] ) {
                        vis[ temp.u[0] ][ temp.u[1] ] = true;
                        q.push( temp );
                    }
                }
    }
    for ( ; d >= 0; d -- )
        if ( ~ans[ d ] ) {
            printf("%d %d\n", ans[d], d);
            return;
        }
    // printf("0 0\n");
    return;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        solve( a, b, c, d );
    }
    return 0;
}
