#include <stdio.h>
int main() {
    for ( int i = 1; i <= 9; i++ )
        for ( int j = 1; j <= 9; j++ )
            for ( int k = 1; k <= 9; k++ )
                if ( i * i * i + j * j * j + k * k * k == i * 100 + j * 10 + k )
                    printf("%d\n", i * 100 + j * 10 + k);
    return 0;
}
