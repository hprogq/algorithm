#include <iostream>
#include <cstdio>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("uva679.in", "r", stdin);
    freopen("uva679.out", "w", stdout);
#endif
    int kase;
    scanf("%d", &kase);
    while ( kase-- ) {
        int d, i, k = 1;
        scanf("%d%d", &d, &i);

        while ( --d )
            if ( i % 2 )
                k = k * 2, i = ( i + 1 ) / 2;
            else k = k * 2 + 1, i /= 2;

        printf("%d\n", k);
    }
    scanf("-1");
    return 0;
}
