#include <stdio.h>
#include <string.h>
int opt[100][100], optn;
void getopt(int n) {
    opt[n][0] = (getchar() - 'A' + 1) * 100 + (getchar() - 'A' + 1);
    switch ( opt[n][0] ) {
        case 524: // EXchange
            scanf ("%d %d %d %d\n", &opt[n][1], &opt[n][2], &opt[n][3], &opt[n][4]);
            break;
        case 403: // DeleteColumn
        case 418: // DeleteRow
        case 903: // InsertColumn
        case 918: // InsertRow
            scanf("%d", &opt[n][1]);
            for ( int i = 1; i <= opt[n][1]; i++ )
                scanf("%d", &opt[n][1 + i]);
            getchar();
            break;
        default:
            break;
    }
    return;
}
void getcom() {
    int r, c, exist = 1;
    scanf("%d%d", &r, &c);
    printf("Cell data in (%d,%d)", r, c);
    for ( int i = 1; i <= optn && exist ; i++ ) {
        int change = 0;
        switch ( opt[i][0] ) {
            case 524: // EXchange
                if ( opt[i][1] == r && opt[i][2] == c )
                    r = opt[i][3], c = opt[i][4];
                else if ( opt[i][3] == r && opt[i][4] == c )
                    r = opt[i][1], c = opt[i][2];
                break;
            case 403: // DeleteColumn
                for ( int j = 1; j <= opt[i][1]; j++ )
                    if ( opt[i][1 + j] < c )
                        change++;
                    else if ( opt[i][1 + j] == c )
                        exist = 0;
                c -= change;
                break;
            case 418: // DeleteRow
                for ( int j = 1; j <= opt[i][1]; j++ )
                    if ( opt[i][1 + j] < r )
                        change++;
                    else if ( opt[i][1 + j] == r )
                        exist = 0;
                r -= change;
                break;
            case 903: // InsertColumn
                for ( int j = 1; j <= opt[i][1]; j++ )
                    if ( opt[i][1 + j] <= c )
                        change++;
                c += change;
                break;
            case 918: // InsertRow
                for ( int j = 1; j <= opt[i][1]; j++ )
                    if ( opt[i][1 + j] <= r )
                        change++;
                r += change;
                break;
            default:
                break;
        }
    }
    if ( exist )
        printf(" moved to (%d,%d)\n", r, c);
    else printf(" GONE\n");
    return;
}
int main( void ) {
#ifdef LOCAL
    freopen("uva512.in", "r", stdin);
    freopen("uva512.out", "w", stdout);
#endif
    int r, c, temp, p = 0;
    while ( ~scanf("%d %d\n", &r, &c) && r != 0 ) {
        scanf("%d\n", &optn);
        for ( int i = 1; i <= optn; i++ )
            getopt(i);
        if ( p++ )
            printf("\n");
        printf("Spreadsheet #%d\n", p);
        scanf("%d", &temp);
        for ( int i = 1; i <= temp; i++ )
            getcom();
    }
    return 0;
}
