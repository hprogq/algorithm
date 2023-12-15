#include <stdio.h>

void max( int x, int y ) {
    printf("%d\n", x > y ? x : y);
    return;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    max(x, y);
    return 0;
}
