#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXL = 7;

int read_num() {
    int temp;
    scanf("%d", &temp);
    return temp;
}

void insert( vector<int>& b, int l, int r, int c ) {
    b[l] += c;
    b[ r - 1 ] -= c;
}

int main() {
    int t;
    scanf("%d\n", &t);
    int w = 0;
    while ( w < t ) {
        int n;
        scanf("%d\n", &n);

        vector<int> a( n + 1 ), b( n + 1 );
        for ( int i = 1; i <= n; i++ )
            insert( b, i, i, read_num() );
        
        bool ended = false;
        while ( !ended ) {
            char s[MAXL];
            scanf("%s\n", s);
            if ( s[0] == 'E' ) {
                ended = true;
                break;
            }
            int p, q;
            scanf("%d %d\n", &p, &q);
            insert(b, p, q,);
        }
    }
}