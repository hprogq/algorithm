#include <iostream>
using namespace std;
int main() {
    int n, maxn = 0x3f3f3f3f, minn = 0;
    scanf("%d", &n);
    while ( n -- ) {
        int a, b;
        scanf("%d%d", &a, &b);
        maxn = min( maxn, a / b );
        minn = max( minn, a / ( b + 1 ) + 1 );
    }
    printf("%d %d\n", minn, maxn);
    return 0;
}
