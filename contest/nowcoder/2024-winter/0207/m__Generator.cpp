// 对拍用：数据生成器。
#include <iostream>
#include <random>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("temp.in", "w", stdout);
#endif
    int n = 2e3;
    random_device rd;
    mt19937 gen(rd());
    mt19937 gen2(rd());

    uniform_int_distribution<long long> distrib(1, 1e7);
    uniform_int_distribution<long long> indic(0, 2);
    printf("%d\n", n);
    while ( n -- ) {
        int ind = indic(gen2);
        long long dis = distrib(gen);
        if ( ind == 2 && dis % 10 )
            printf("%lld%s", dis % 10, n ? " " : "\n");
        else printf("%lld%s", dis*( ind == 0 ? 36 : 1 ), n ? " " : "\n");
    }
    return 0;
}