#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> p( n + 1, 0 );
    while ( m-- ) {
        int x;
        scanf("%d", &x);
        p[x]++;
    }
    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= p[i]; j++ )
            printf("%d ", i);
    return 0;
}
