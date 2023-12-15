#include <stdio.h>
int main() {
    int a[5], query;
    for ( int i = 0; i < 5; i ++ )
        scanf("%d", &a[i]);
    scanf("%d", &query);
    for ( int i = 0; i < 5; i ++ )
        if ( a[i] == query ) {
            printf("Query success.\n");
            return 0;
        }
    printf("Query failed.\n");
    return 0;
}
