#include <cstdio>
using namespace std;

char hash( int n ) {
    if ( n <= 26 )
        return 'A' + n - 1;
    else return 'a' + n - 27;
}

int main() {
    int n;
    while ( ~scanf("%d", &n) ) {
        printf("%d %d %d\n", 2, n, n);
        for ( int i = 1; i <= n; i ++ ) {
            for ( int j = 1; j <= n; j ++ )
                printf("%c", hash(i));
            puts("");
        }
        puts("");
        for ( int i = 1; i <= n; i ++ ) {
            for ( int j = 1; j <= n; j ++ )
                printf("%c", hash(j));
            puts("");
        }
        puts("");
    }
    return 0;
}