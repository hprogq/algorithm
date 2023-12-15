#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, son[N][26], cnt[N], idx = 0;
    scanf("%d", &n);
    while ( n -- ) {
        char op, str[N];
        scanf("%c %s", &op, str);
        if ( op == 'I' ) {
            int p = 0;
            for ( int i = 0; str[i]; i ++ ) {
                int u = str[i] - 'a';
                if ( !son[p][u] )  son[p][u] = ++ idx;
                p = son[p][u];
                cnt[p] ++;
            }
        } else if ( op == 'Q' ) {
            int p = 0;
            bool s = true;
            for ( int i = 0; str[i]; i ++ ) {
                int u = str[i] - 'a';
                if ( !son[p][u] ) {
                    s = false;
                    break;
                }
                p = son[p][u];
            }
            if ( !s )
                printf("0\n");
            else printf("%d\n", cnt[p]);
        }
    }
    return 0;
}