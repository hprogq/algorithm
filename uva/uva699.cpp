#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

bool dig( map<int, int>& w, int wid ) {
    int x;
    scanf("%d", &x);
    if ( x == -1 )
        return false;
    
    if ( w.find( wid ) != w.end() )
        w[wid] += x;
    else w[wid] = x;

    dig( w, wid - 1 );
    dig( w, wid + 1 );

    return true;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int k = 0;
    for ( ; ; ) {
        map<int, int> w;
        if ( !dig( w, 0 ) )
            return 0;
        // else printf( k ? "\n" : "");
        printf("Case %d:\n", ++k);
        for (auto it = w.begin(); it != w.end(); ++it)
            printf("%d%s", it -> second, it == prev(w.end()) ? "" : " ");
        printf("\n\n");
    }
    return 0;
}
