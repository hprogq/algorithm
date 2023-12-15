#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n, l, a = 0;
    scanf("%d%d", &n, &l);
    while ( n -- ) {
        int k;
        scanf("%d", &k);
        if ( k >= l )
            a ++;
    }
    printf("%d\n", a);
    return 0;
}
