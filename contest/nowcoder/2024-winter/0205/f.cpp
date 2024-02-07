#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
typedef pair<int, int> pir;
const int N = 2e5 + 10;
int main() {
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        int n;
        int w[N] = {0}, l[3] = {0};
        scanf("%d", &n);
        for ( int i = 1; i <= n; i ++ ) {
            int c;
            scanf("%d", &c);
            l[c] = i;
            w[i] = l[1] > l[2] ? l[2] ? l[2] : l[1] : l[1] ? l[1] : l[2]; 
        }
        int s = n, a = 0;
        while ( s )
            s = w[s] - 1, a ++;
        printf("%d\n", a);
    }
    return 0;
}
