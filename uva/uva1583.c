#include <stdio.h>
#define MAXN 100005
int num[MAXN] = {0};
int gen(int n) {
    int sum = n;
    while ( n != 0 ) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main(void) {
    for ( int i = 1; i <= MAXN; i++ ) {
        int t = gen(i);
        if ( !num[t] )
            num[t] = i;
    }
    int n;
    scanf("%d", &n);
    while ( n-- ) {
        int q;
        scanf("%d", &q);
        printf("%d\n", num[q]);
    }
    return 0;
}
