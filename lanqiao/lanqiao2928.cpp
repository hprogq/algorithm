#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    char s[N];
    scanf("%s", s);
    sort(s, s + n);
    printf("%c", s[x - 1]);
    if (s[0] != s[x - 1])
        return 0;
    if (n > x && s[x] == s[n - 1])
        for (int i = 1; i <= n / x - 1 + (n % x ? 1 : 0); i ++)
            printf("%c", s[x]);
    else printf("%s", s + x);
    return 0;
}
