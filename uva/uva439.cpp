#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pos;
typedef pair<pos, int> stat;

const int M = 8;
const int dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
const int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    char s[3], e[3];
    while ( ~scanf("%s %s", s, e) ) {
        pos start( s[0] - 'a', s[1] - '1' );
        pos end( e[0] - 'a', e[1] - '1' );
        if ( start == end ) {
            printf("To get from %s to %s takes %d knight moves.\n", s, e, 0);
            continue;
        }
        queue<stat> que;
        set<pos> vis;
        bool flag = true;
        que.push( stat( start, 0 ) );
        vis.insert(start);
        while ( flag && !que.empty() ) {
            auto [ ppos, step ] = que.front();
            que.pop();
            for ( int i = 0; i < M; i ++ ) {
                pos npos( ppos.first + dx[i], ppos.second + dy[i] );
                if ( vis.find(npos) != vis.end() || !( npos.first >= 0 && npos.second >= 0 && npos.first < M && npos.second < M ) )
                    continue;
                vis.insert(npos);
                if ( npos == end ) {
                    printf("To get from %s to %s takes %d knight moves.\n", s, e, step + 1);
                    flag = false;
                } else que.push( stat( npos, step + 1 ) );
            }
        }
    }
    return 0;
}
