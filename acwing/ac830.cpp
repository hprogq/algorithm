#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, stk[N] = {0}, tt = 0;
    scanf("%d", &n);
    while ( n-- ) {
        int t;
        scanf("%d", &t);
        while ( tt && stk[tt] >= t )
            tt--;
        if ( tt )
            printf("%d ", stk[ tt ]);
        else printf("-1 ");
        
        stk[ ++tt ] = t;
    }
    return 0;
}
