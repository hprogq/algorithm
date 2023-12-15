#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int main() {
    int n, m, ne[N];
    char s[N], p[N];
    cin >> s + 1 >> p + 1;
    n = strlen(p + 1);
    m = strlen(s + 1);
    for ( int i = 2, j = 0; i <= n; i++ ) {
        while ( j && p[i] != p[ j + 1 ] )  j = ne[j];
        if ( p[i] == p[ j + 1 ] )  j++;
        ne[i] = j;
    }
    for ( int i = 1, j = 0; i <= m; i++ ) {
        while ( j && s[i] != p[ j + 1 ] )  j = ne[j];
        if ( s[i] == p[ j + 1 ] )  j++;
        if ( j == n ) {
            printf("%d\n", i - n + 1);
            j = ne[j];
        }
    }
    for ( int i = 1; i <= n; i++ )
        printf("%d ", ne[i]);
    return 0;
}
