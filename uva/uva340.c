#include <stdio.h>
#define MAXN 1010
int min(int a, int b) {
    if ( a > b )
        return b;
    else return a;
}
int main(void) {
    freopen("uva340.in", "r", stdin);
    freopen("uva340.out", "w", stdout);
    int n, d = 0;
    while ( scanf("%d", &n) == 1 && n ) {
        d++;
        int ans[MAXN], appear[MAXN] = {0};
        printf("Game %d:\n", d);
        for ( int i = 1; i <= n; i++ ) {
            scanf("%d", &ans[i]);
            appear[ans[i]]++;
        }
        int run = 1;
        while ( run ) {
            int A = 0, B = 0;
            int temp[MAXN], same[10] = {0}, time[10] = {0};
            for ( int i = 1; i <= n; i++ ) {
                scanf("%d", &temp[i]);
                time[temp[i]]++;
                if ( temp[i] == 0 )
                    run = 0;
                if ( temp[i] == ans[i] ) {
                    A++;
                    same[temp[i]]++;
                }
            }
            if ( !run )
                break;
            for ( int i = 1; i <= 9; i++ )
                if ( appear[i] && time[i] ) {
                    // printf("%d %d %d\n", i, time[i], same[i]);
                    B += min( appear[i], time[i] ) - same[i];
                }
            printf("    (%d,%d)\n", A, B);
        }
    }
}