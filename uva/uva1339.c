#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 105
#define DICT 26
int cmp( const void *a, const void *b ) {
    return *(int *)a - *(int *)b;
}
int main( void ) {
    char s1[MAXL], s2[MAXL];
    while ( ~scanf("%s%s", s1, s2) ) {
        int cnt1[DICT] = {0}, cnt2[DICT] = {0};
        int len = strlen(s1);
        for ( int i = 0; i < len; i++ ) {
            cnt1[ s1[i] - 'A' ]++;
            cnt2[ s2[i] - 'A' ]++;
        }
        qsort(cnt1, DICT, sizeof(int), cmp);
        qsort(cnt2, DICT, sizeof(int), cmp);
        int flag = 1;
        for ( int i = 0; i < DICT; i++ )
            if ( cnt1[i] != cnt2[i] ) {
                flag = !flag;
                break;
            }
        if ( flag )
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
