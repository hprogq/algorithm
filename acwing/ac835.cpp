#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e4 + 10, L = 1e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v, id = 0, son[N][26] = {0}, cnt[N] = {0}, i, p = 0;;
    char str[L], op[2];
    scanf("%d", &v);
    while ( v -- ) {
        scanf("%s%s", op, str);
        if ( *op == 'I' ) {
            for ( i = 0, p = 0; i < strlen(str); i ++ ) {
                if ( !son[p][ str[i] - 'a' ] )
                    son[p][ str[i] - 'a' ] = ++ id;
                p = son[p][ str[i] - 'a' ];
            }
            cnt[p] ++;
        } else if ( *op == 'Q' ) {
            for ( i = 0, p = 0; i < strlen(str); i ++ ) {
                if ( !son[p][ str[i] - 'a' ] ) {
                    p = 0;
                    break;
                } else p = son[p][ str[i] - 'a' ];
            }
            printf("%d\n", cnt[p]);
        }
    }
    return 0;
}
