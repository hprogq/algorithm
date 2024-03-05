#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pir;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, k;
    // 本题实际上是两个单调栈（单调增、单调减）的组合问题。
    // 由于本题需要在栈尾新增元素的同时从栈头推出元素，可以使用双端队列deque。
    deque<pir> q1, q2; // 存储的是pair<int, int>，具体实现可以看下方代码。
    scanf("%d%d", &n, &k);
    vector<int> minn, maxn;
    // 这里的i的实际意义是窗口尾部的位置。在本次循环后，将推入第i个元素。
    for ( int i = 1; i <= n; i ++ ) {
        int t;
        scanf("%d", &t);

        // 下方语句模拟移动窗口时左侧出栈的过程。
        // 单调栈内的元素是窗口内全部元素的子集。
        // 通过检查栈头元素编号与当前编号的差值，就可以知道栈头元素是否需要推出。
        if ( !q1.empty() && i - q1.front().second == k )
            q1.pop_front();
        if ( !q2.empty() && i - q2.front().second == k )
            q2.pop_front();

        // 单调栈入栈。新元素会导致部分数据变为无价值数据。
        // 此时需要推出所有无价值数据，然后再将新数据推入。
        while ( !q1.empty() && t < q1.back().first )
            q1.pop_back();
        while ( !q2.empty() && t > q2.back().first )
            q2.pop_back();
        // 推入队列时在这里同时存入其编号。
        q1.push_back( pir(t, i) );
        q2.push_back( pir(t, i) );

        // 在窗口尾部移动到第k个元素后方时，窗口形成，开始存储最大值、最小值。
        if ( i >= k ) {
            minn.push_back( q1.empty() ? -1 : q1.front().first );
            maxn.push_back( q2.empty() ? -1 : q2.front().first );
        }
    }
    // 使用C++11特性进行简单地遍历输出。
    for ( int e : minn )
        printf("%d ", e);
    puts("");
    for ( int e : maxn )
        printf("%d ", e);
    return 0;
}
