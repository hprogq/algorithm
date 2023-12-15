#include <stdio.h>
#define MAX 10
int main(void) {
    for ( int i = 1; i <= MAX; i++ )
        for ( int j = 1; j <= MAX; j++ )
            for ( int k = 1; k <= MAX; k++ )
                if ( i * i * i + j * j * j + k * k * k == i * 100 + j * 10 + k )
                    printf("%d\n", i * 100 + j * 10 + k);
    return 0;
}
