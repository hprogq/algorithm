#include <iostream>
using namespace std;
int n, num[15], list[15];
bool vis[15];

void dfs( int c, int k ) {
    if ( k == c )
        for ( int i = 1; i <= c; i ++ )
            printf("%d%c", list[i], i == c ? '\n' : ' ');
    else for ( int x = 1; x <= c; x ++ )
        if ( !vis[x] ) {
            vis[x] = true;
            list[ k + 1 ] = x;
            dfs( c, k + 1 );
            vis[x] = false;
        }
    return;
}

int main() {
    scanf("%d", &n);
    dfs( n, 0 );
}
