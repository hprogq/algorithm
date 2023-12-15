#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200003, nul = 0x3f3f3f3f;

int find( int p[], int x ) {
    int k = ( x % N + N ) % N;
    while ( p[k] != nul && p[k] != x )
        if ( ++ k == N )
            k = 0;
    return k;
}

int main() {
    int n, p[N];
    memset( p, 0x3f, sizeof(p) );
    scanf("%d", &n);
    while ( n -- ) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        int t = find( p, x );
        if ( *op == 'I' )
            p[t] = x;
        else printf( p[t] == nul ? "No\n" : "Yes\n" );
    }
    return 0;
}
