#include <stdio.h>
#include <string.h>
#define MAXN 105
int main(void) {
    int num = 0;
    scanf("%d", &num);
    while ( num-- ) {
        char str[MAXN];
        scanf("%s", str);
        int offset = 0, len = strlen(str);
        for ( int i = 1; i < len; i++ ) {
            int flag = 0;
            for ( int j = 0; j < len && !flag; j++ )
                flag = str[ (offset + j) % len ] - str[ ( i + j ) % len ];
            if ( flag > 0 )
                offset = i;

        }
        for ( int i = 0 + offset; i < len + offset; i++ )
            printf("%c", str[i % len]);
        printf("\n");
    }
    return 0;
}
