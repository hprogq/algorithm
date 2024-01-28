#include <cstdio>
#include <algorithm>
using namespace std;
int N = 1e4 + 10;
int main() {
    int a[N];
    int n, x = 0;
    scanf("%d", &n);
    while ( ~scanf("%d", &a[x ++]) );
    sort(a, a + -- x);
    int t = a[0], b, r;
    for ( int i = 1; i < x; i ++ ) {
        if ( a[i] == t )
            r = t;
        else if ( a[i] == t + 2 )
            b = t + 1, t = a[i];
        else t ++;
    }
    printf("%d %d\n", b, r);
    return 0;
}
