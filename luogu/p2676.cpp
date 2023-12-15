#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, b;
    scanf("%d%d", &n, &b);
    vector<int> h(n);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &h[i]);
    sort( h.begin(), h.end(), greater<int> () );
    int k = 0, s = 0;
    while ( s < b )
        s += h[k++];
    printf("%d\n", k);
    return 0;
}
