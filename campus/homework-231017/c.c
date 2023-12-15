#include <stdio.h>
int main() {
    float x, y, z;
    scanf("%f%f%f", &x, &y, &z);
    float aver = ( x + y + z ) / 3;
    printf("%f\n", aver);
    return 0;
}
