#include <iostream>
#include <cstdio>
using namespace std;

int dig() {
    int w_l, d_l, w_r, d_r;
    scanf("%d%d%d%d", &w_l, &d_l, &w_r, &d_r);
    if ( !w_l )
        w_l = dig();
    if ( !w_r )
        w_r = dig();
    if ( !~w_l || !~w_r || w_l * d_l != w_r * d_r )
        return -1;
    return w_l + w_r;
}

int main() {
    int k;
    scanf("%d", &k);
    while ( k-- )
        if ( ~dig() )
            printf(k ? "YES\n\n" : "YES\n");
        else printf(k ? "NO\n\n" : "NO\n");
    return 0;
}
