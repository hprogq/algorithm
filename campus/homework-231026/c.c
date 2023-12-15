#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    printf( "%s\n", ( !( a % 5 ) && !( a % 7 ) ) ? "yes" : "no" );
    return 0;
}
