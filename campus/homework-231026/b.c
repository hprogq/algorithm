#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    printf( "%s\n", ( ( !( a % 4 ) && ( a % 100 ) ) || !( a % 400 ) ) ? "YES" : "NO" );
    return 0;
}
