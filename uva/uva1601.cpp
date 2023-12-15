#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <tuple>
#include <queue>
#include <unordered_set>
using namespace std;

typedef pair<int, int> pir;
typedef tuple<pir, pir, pir> grp;
typedef pair<int, grp> st;

const pir nul( -1, -1 );
const int N = 16, P = 3;
const int dr[] = { 0, 1, 0, -1 },
          dc[] = { -1, 0, 1, 0 };

grp mkg( int n, pir a, pir b = nul, pir c = nul ) {
    switch (n) {
        case 1: return grp( a, nul, nul );
        case 2: return grp( a, b, nul );
        case 3: return grp( a, b, c );
    }
}

int main() {
    int w, h, n;
    while ( ~scanf("%d %d %d\n", &w, &h, &n) & w ) {
        bool g[N][N] = { false }, rd[N][N][N][N] = { false };
        pir from[P], to[P];
        memset( from, -1, sizeof(from) );
        memset( to, -1, sizeof(to) );
        for ( int r = 0; r < w; r ++ ) {
            string s;
            getline( cin, s );
            for ( int c = 0; c < w; c ++ ) {
                char t = s[c];
                if ( islower(t) )
                    from[ t - 'a' ] = pir( r, c );
                else if ( isupper(t) )
                    to[ t - 'A' ] = pir( r, c );
                else g[N][N] = ( t == '#' );
            }
        }
        for ( int r = 0; r < w; r ++ )  for ( int c = 0; c < w; c ++ ) if ( !g[r][c] )
            for ( int tr = -1; tr <= 1; tr ++ )  for ( int tc = -1; tc <= 1; tc ++ ) {
                int nr = r + dr[tr], nc = c + dc[tc];
                if ( nr >= 0 && nc >= 0 && nr < w && nc < w && !g[nr][nc] )
                    rd[r][c][nr][nc] = true;
            }
        
        queue<st> q;
        unordered_set<grp> v;
        grp f = mkg( n, from[0], from[1], from[2] ), t = mkg( n, to[0], to[1], to[2] );
        q.push( st(0, f) );  v.insert(f);
        while ( !q.empty() ) {
            st t = q.front();  q.pop();
            auto [ d, g ] = t;
            auto [ a, b, c ] = g;
        }
    }
    return 0;
}
