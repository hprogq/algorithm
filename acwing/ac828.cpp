#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int m, que[N] = { 0 }, idx = 0;
    scanf("%d\n", &m);
    while ( m-- ) {
        int k;
        string s;
        cin >> s;
        if ( s == "push" )
            scanf("%d\n", &k);
        
        if ( s == "push" )
             que[ ++ idx ] = k;
        else if ( s == "pop" )
            idx--;
        else if ( s == "query" )
            printf("%d\n", que[idx]);
        else if ( s == "empty" )
            printf("%s\n", idx ? "NO" : "YES");
    }
    return 0;
}
