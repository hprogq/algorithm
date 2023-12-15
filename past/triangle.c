#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int t1 = 2 * n - 1;
    int t2 = 0;
    while (t1 > 0)
    {
        for (int i = 1; i <= t2; i++)
            printf(" ");
        for (int i = 1; i <= t1; i++)
            printf("#");
        printf("\n");
        t1 -= 2;
        t2++;
    }
    return 0;
}
