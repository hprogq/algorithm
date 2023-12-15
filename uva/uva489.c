#include <stdio.h>
#include <string.h>
#define DICT 26
#define MAXT 7
int main( void ) {
#ifdef LOCAL
    freopen("uva489.in", "r", stdin);
    freopen("uva489.out", "w", stdout);
#endif
    int index;
    while ( scanf("%d\n", &index) && index != -1 ) {
        printf("Round %d\n", index);
        int c, ans[DICT] = {0}, attempts[DICT] = {0}, chance = MAXT, letters = 0;
        while ( ( c = getchar() ) != '\n' )
            ans[c - 'a']++;
        for ( int i = 0; i < DICT; i++ )
            if ( ans[i] )
                letters++;
        while ( ( c = getchar() ) != '\n' ) {
            if ( chance != 0 && letters != 0 ) {
                if ( attempts[c - 'a'] ) {
                    ;
                } else if ( ans[c - 'a'] ) {
                    ans[c - 'a'] = 0;
                    letters--;
                } else chance--;
                attempts[c - 'a']++;
            }
        }
        if ( chance == 0 )
            printf("You lose.\n");
        else if ( letters == 0 )
            printf("You win.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}
