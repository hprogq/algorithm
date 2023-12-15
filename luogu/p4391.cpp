#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int main() {
    char s[N];
    int l;
    scanf("%d\n", &l);
    scanf("%s", s + 1);
    int ne[N] = { 0 };
    for ( int i = 2, j = 0; i <= l; i ++ ) {
        while ( j && s[i] != s[ j + 1 ] )  j = ne[j];
        if ( s[i] == s[ j + 1 ] )  j ++;
        ne[i] = j;
    }
    printf("%d\n", l - ne[l]);
    return 0;
}
