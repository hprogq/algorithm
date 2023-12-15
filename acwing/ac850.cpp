#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10, INF = 0x3f3f3f3f;

int n, m, h[N], w[N], e[N], ne[N], d[N], idx = 0;
bool st[N];

void link( int a, int b, int c ) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
    return;
}

int dijkstra() {
    memset( d, 0x3f, sizeof(d) );
    d[1] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
    q.push( make_pair( 0, 1 ) );
    
    while ( !q.empty() ) {
        auto t = q.top();  q.pop();
        int td = t.first, tp = t.second;

        if ( st[tp] )
            continue;
        st[tp] = true;

        for ( int i = h[tp]; ~i; i = ne[i] )
            if ( d[ e[i] ] > td + w[i] ) {
                d[ e[i] ] = td + w[i];
                q.push( make_pair ( d[ e[i] ], e[i] ) );
            }
    }

    if ( d[n] == INF )
        return -1;
    else return d[n];
}

int main() {
    memset( h, -1, sizeof(h) );
    scanf("%d%d", &n, &m);
    while ( m -- ) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        link( a, b, c );
    }

    printf("%d\n", dijkstra());

    return 0;
}
