#include <stdio.h>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf( "%d\n", c < ( a < b ? a : b ) ? c : ( a < b ? a : b ) );
    return 0;
}
