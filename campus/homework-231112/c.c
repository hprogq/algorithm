#include <stdio.h>
int main() {
    int i = 1, sum = 0;
    do sum += ( 2 * i - 1 ) * ( 2 * i - 1 );
    while ( ++i <= 50 );
    printf("%d\n", sum);
    return 0;
}
