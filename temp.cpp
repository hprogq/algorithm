#include <iostream>
using namespace std;
const int N = 99999;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    printf("%d\n", N);
    for ( int i = 1; i < N; i ++ )
        printf("%d ", i + 1);
    printf("%d\n", 1);
}
