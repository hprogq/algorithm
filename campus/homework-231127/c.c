#include <stdio.h>
int main() {
    int a[5], maxn = -0x7fffffff;
    for ( int i = 0; i < 5; i ++ ) {
        scanf("%d", &a[i]);
        maxn = maxn < a[i] ? a[i] : maxn;
    }
    printf("%d\n", maxn);
    return 0;
}
