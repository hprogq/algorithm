#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("uva514.in", "r", stdin);
    freopen("uva514.out", "w", stdout);
#endif
    int n;
    while ( scanf("%d", &n), n ) {
        bool end = false;
        while ( !end ) {
            vector<int> target( n + 1 );
            for ( int i = 1; i <= n && ( i == 1 || target[1] ); i++ )
                scanf("%d", &target[i]);
            if ( !target[1] ) {
                end = true;
                continue;
            }
            stack<int> b;
            bool flag = true;
            int A = 1, B = 1;
            while ( B <= n && flag ) {
                if ( A == target[B] )
                    A++, B++;
                else if ( !b.empty() && b.top() == target[B] )
                    b.pop(), B++;
                else if ( A <= n )
                    b.push(A++);
                else flag = false;
            }
            printf( "%s\n", flag ? "Yes" : "No" );
        }
        printf("\n");
    }
    return 0;
}
