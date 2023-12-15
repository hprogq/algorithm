#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
const int N = 35;

bool check( int (&p)[N], int t ) {
    for ( int i = 1; i < t; i ++ )
        if ( p[i] > p[ i - 1 ] )
            return false;
    return true;
}

int find( int (&p)[N], int d, int t ) {
    for ( int i = 0; i < t; i ++ )
        if ( p[i] == d )
            return i;
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin.tie(0);
    string s;
    while ( getline( cin, s ) && s.length() ) {
        int t = 0, w[N], a[N], p[N], idx = 0, move = 0;
        stringstream ss(s);
        while ( ss >> w[t] )  t ++;
        memcpy( a, w, sizeof(w) );
        memcpy( p, w, sizeof(w) );
        sort( w, w + t );
        cout << s << endl;
        while ( move != t && !check( p, t ) ) {
            int d = w[ idx ++ ], f = find( p, d, t );
            if ( f == t - idx ) {
                move ++;
                continue;
            }
            if ( f ) {
                reverse( p, p + f + 1 );
                printf("%d ", t - f);
            }
            reverse( p, p + t - move );
            printf("%d ", ++ move);
        }
        printf("%d %d\n", 1, 0);
    }
    return 0;
}
