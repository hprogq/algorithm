#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
const int maxr = 10000 + 5;
const int maxc = 10 + 2;
typedef pair<int, int> PAIR;
int main() {
#ifdef LOCAL
    freopen("uva1592.in", "r", stdin);
    freopen("uva1592.out", "w", stdout);
#endif
    int r, c;
    while ( ~scanf("%d %d\n", &r, &c) ) {
        map<string, int> hash;
        int table[maxr][maxc] = {0};
        for ( int x = 0, i = 1; i <= r; i++ )
            for ( int j = 1; j <= c; j++ ) {
                string s;
                getline(cin, s, j == c ? '\n' : ',');
                if ( hash.count(s) )
                    table[i][j] = hash[s];
                else hash[s] = table[i][j] = ++x;
            }
        int c1, c2, r0;
        bool flag = true;
        for ( c1 = 1; flag && c1 <= c; c1++ )
            for ( c2 = c1 + 1; flag && c2 <= c; c2++ ) {
                map<PAIR, int> m;
                for ( r0 = 1; flag && r0 <= r; r0++ )
                    if ( m.count( PAIR( table[r0][c1], table[r0][c2] ) ) ) {
                        printf("NO\n%d %d\n%d %d\n", m[PAIR( table[r0][c1], table[r0][c2] )], r0, c1, c2);
                        flag = false;
                    } else m[ PAIR( table[r0][c1], table[r0][c2] ) ] = r0;
            }
        if ( flag )
            printf("YES\n");
    }
    return 0;
}
