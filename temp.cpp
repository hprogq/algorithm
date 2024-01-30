#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
string s;

int main()
{
    cin >> n >> x >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[n - 1])
    {
        for (int i = 0; i < (n + x - 1) / x; i++)
            printf("%c", s[0]);
    }
    else if (s[0] == s[x - 1])
    {
        for (int i = x - 1; i < s.length(); i++)
            printf("%c", s[i]);
    }
    else
        printf("%c", s[x - 1]);
    return 0;
}
