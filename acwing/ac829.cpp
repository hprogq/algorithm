#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int m, que[N] = { 0 }, begin = 0, end = 0;
    scanf("%d\n", &m);
    while ( m-- ) {
        int k;
        string s;
        cin >> s;
        if ( s == "push" )
            scanf("%d\n", &k);
        
        if ( s == "push" )
             que[ ++ end ] = k;
        else if ( s == "pop" )
            begin++;
        else if ( s == "query" )
            printf("%d\n", que[ begin + 1 ]);
        else if ( s == "empty" )
            printf("%s\n", end - begin ? "NO" : "YES");
    }
    return 0;
}
