#include <stdio.h>
int n[10];
int a, b, c, d, e, f, g, h, i;
int tri(int a, int b, int c)
{
    return a * 100 + b * 10 + c;
}
int main(void)
{
    for (a = 1; a <= 9; a++)
    {
        n[a]++;
        for (b = 1; b <= 9; b++)
        {
            n[b]++;
            for (c = 1; c <= 9; c++)
            {
                n[c]++;
                for (d = 1; d <= 9; d++)
                {
                    n[d]++;
                    for (e = 1; e <= 9; e++)
                    {
                        n[e]++;
                        for (f = 1; f <= 9; f++)
                        {
                            n[f]++;
                            for (g = 1; g <= 9; g++)
                            {
                                n[g]++;
                                for (h = 1; h <= 9; h++)
                                {
                                    n[h]++;
                                    for (i = 1; i <= 9; i++)
                                    {
                                        n[i]++;
                                        int ok = 1;
                                        for (int t = 1; t <= 9; t++)
                                            if (n[t] != 1)
                                                ok = 0;
                                        int x = tri(a, b, c);
                                        int y = tri(d, e, f);
                                        int z = tri(g, h, i);
                                        if (ok == 1 && y == 2 * x && z == 3 * x)
                                            printf("%d %d %d\n", x, y, z);
                                        n[i]--;
                                    }
                                    n[h]--;
                                }
                                n[g]--;
                            }
                            n[f]--;
                        }
                        n[e]--;
                    }
                    n[d]--;
                }
                n[c]--;
            }
            n[b]--;
        }
        n[a]--;
    }
    return 0;
}