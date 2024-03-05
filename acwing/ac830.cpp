#include <iostream>
#include <stack>
using namespace std;
int main() { // 单调栈特性：每个元素最多仅遍历、入栈和出栈一次。
    int n;
    stack<int> s;
    scanf("%d", &n);
    while ( n -- ) {
        int t;
        scanf("%d", &t);
        while ( !s.empty() && s.top() >= t ) // 维护一个单调的栈，使其中只有有价值的元素（单调）。
            s.pop(); // 一直出栈，直到栈顶比输入数小。此时出栈的元素已经无用了，因为之后选这些元素都不如选输入数t。
        if ( !s.empty() ) // 如果栈不空，再输出。
            printf("%d ", s.top());
        else printf("-1 ");
        s.push(t); // 将元素插入栈顶。
    }
    return 0;
}
