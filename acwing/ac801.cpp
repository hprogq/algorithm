#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    while ( n-- ) {
        int t, k = 0;
        scanf("%d", &t);
        while ( t ) {
            t -= t & (-t);
            k++;
        }
        printf("%d ", k);
    }
    return 0;
}
