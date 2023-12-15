#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <stack>
#include <queue>
#include <set>
#include <sstream>
using namespace std;
const int L = 20;

struct axis {
    int r, c;

    axis( int r, int c ): r(r), c(c) {}
};

struct edge {
    axis pos;
    int dir;

    edge( axis pos, int dir ): pos(pos), dir(dir) {}
};

struct stat {
    axis now;
    int dir;

    stat( axis now, int dir ): now(now), dir(dir) {}
};

const string turns = "LFR";
const string dirs = "ESWN";

const int d_turn[] = { -1, 0, 1 };
const int d_move_r[] = { 0, 1, 0, -1 };
const int d_move_c[] = { 1, 0, -1, 0 };

int input_dir( char c ) {
    auto f = dirs.find(c);
    if ( f != string::npos )
        return (int) f;
    return -1;
}

int input_turn( char c ) {
    auto f = turns.find(c);
    if ( f != string::npos )
        return (int) f - 1;
    return -1;
}

axis move( axis p, axis max, int dir ) {
    int r = p.r + d_move_r[dir], c = r + d_move_r[dir];
    if ( r <= 0 || r > max.r || c <= 0 || c > max.c )
        return axis( false, false );
    return axis( r, c );
}

int turn( int dir, int turn ) {
    return ( dir + turn + 4 ) % 4;
}

void print_axis( axis x, int c ) {
    printf("%s(%d,%d)%s", c == 1 ? " " : "", x.r, x.c, !( c % 10 ) ? "\n" : " ");
    return;
}

void print( stat x, axis begin, map<stat, stat>& path ) {
    queue<axis> ans;
    while ( x.now.r != begin.r && x.now.c != begin.c ) {
        ans.push( x.now );
        x = path[x];
    }
    int count = 0;
    while ( !ans.empty() )
        print_axis( ans.front(), ++count );
    return;
}

int main() {
#ifdef LOCAL
    freopen("uva816.in", "r", stdin);
    freopen("uva816.out", "w", stdout);
#endif
    char name[L];
    while ( fgets(name, L, stdin) && strcmp(name, "END\n") != 0 ) {
        printf("%s\n", name);
        axis begin(0, 0), end(0, 0), max(0, 0);
        char begin_dir;
        scanf("%d %d %c %d %d\n", &begin.r, &begin.c, &begin_dir, &end.r, &end.c);
        set<edge> edges;
        for ( ; ; ) {
            axis t(0, 0);

            string s;
            getline( cin, s );
            stringstream ss(s);

            ss >> t.r;
            if ( !t.r )
                break;
            ss >> t.c;

            max.r = t.r > max.r ? t.r : max.r;
            max.c = t.c > max.c ? t.c : max.c;

            for ( ; ; ) {
                string g;
                ss >> g;
                if ( g[0] == '*' )
                    break;
                int face_dir = input_dir( g[0] );
                for ( int i = 1; i < g.length(); i++ )
                    edges.insert( edge( t, turn( face_dir, input_turn( g[i] ) ) ) );
            }
        }
        queue<stat> que;
        unordered_map<stat, stat> path;
        // axis begin_real = move( begin, max, input_dir( begin_dir ) );
        que.push( stat( begin, begin_dir ) );
        while ( !que.empty() ) {
            stat top = que.front();
            axis now(0, 0);
            int dir;
            if ( now.r == end.r && now.c == end.c  ) {
                print( top, begin, path );
                break;
            }
            que.pop();
            axis next = move( now, max, dir );
            for ( int i = -1; i <= 1; i++ )
                if ( edges.count( edge( now, turn( dir, i ) ) ) > 0 ) {
                    path[ stat( next, i ) ] = top;
                    que.push( stat( next, i ) );
                }
        }
    }
    return 0;
}
