#include <stdio.h>
int main() {
    int i = 0, sum = 0;
    while ( ++i <= 50 )
        sum += ( 2 * i - 1 ) * ( 2 * i - 1 );
    printf("%d\n", sum);
    return 0;
}
