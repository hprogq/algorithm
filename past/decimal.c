#include <stdio.h>
int main(void)
{
    int a, b, c;
    while (~scanf("%d %d %d", &a, &b, &c) && a + b + c != 0)
    {
        int integer = a / b;
        printf("%d.", integer);
        int temp = a - b * integer, decimals = 0;
        while (decimals <= c)
        {
            decimals++;
            temp *= 10;
            int tdec = temp / b;
            if (decimals == c)
            {
                temp = (temp % b) * 10;
                int tdec2 = temp / b;
                if (tdec2 < 5)
                    printf("%d", tdec);
                else
                    printf("%d", tdec + 1);
                break;
            }
            else
                printf("%d", tdec);
            temp %= b;
        }
        printf("\n");
    }
    return 0;
}