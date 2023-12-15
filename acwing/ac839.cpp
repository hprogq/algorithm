#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define size Size
using namespace std;

const int N = 1e5 + 10;
int heap[N], ph[N], hp[N], size;

void swp( int a, int b ) {
    swap( heap[a], heap[b] );
    swap( hp[a], hp[b] );
    swap( ph[ hp[a] ], ph[ hp[b] ] );
    return;
}

void down( int x ) {
    int t = x;
    if ( 2 * x <= size && heap[t] > heap[ 2 * x ] )
        t = 2 * x;
    if ( 2 * x + 1 <= size && heap[t] > heap[ 2 * x + 1 ] )
        t = 2 * x + 1;
    if ( t != x ) {
        swp( t, x );
        down(t);
    }
    return;
}

void up( int x ) {
    while ( x / 2 && heap[x] < heap[ x / 2 ] ) {
        swp( x, x / 2 );
        x /= 2;
    }
    return;
}

int main() {
    int n, cnt = 0, k, x;
    scanf("%d", &n);
    while ( n -- ) {
        char op[3];
        scanf("%s", op);
        if ( !strcmp( op, "I" ) ) {
            scanf("%d", &x);
            size ++, cnt ++;
            heap[size] = x;
            ph[cnt] = size, hp[size] = cnt;
            up(size);
        } else if ( !strcmp( op, "PM" ) ) {
            printf("%d\n", heap[1]);
        } else if ( !strcmp( op, "DM" ) ) {
            swp( 1, size -- );
            down(1);
        } else if ( !strcmp( op, "D" ) ) {
            scanf("%d", &k);
            int t = ph[k];
            swp( size --, t );
            up(t);
            down(t);
        } else if ( !strcmp( op, "C" ) ) {
            scanf("%d%d", &k, &x);
            int t = ph[k];
            heap[t] = x;
            up(t);
            down(t);
        }
    }
    return 0;
}
