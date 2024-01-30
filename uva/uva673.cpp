#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin.tie(0);
    int n;
    scanf("%d\n", &n);
    while ( n -- ) {
        string t;
        getline(cin, t);
        stack<char> s;
        bool flag = true;
        for ( int i = 0; i < t.length(); i ++ ) {
            char x = t[i];
            if ( x == '[' || x == '(' )
                s.push(x);
            if ( x == ']' )
                if ( s.empty() || s.top() != '[' ) {
                    flag = false;
                    break;
                } else s.pop();
            if ( x == ')' )
                if ( s.empty() || s.top() != '(' ) {
                    flag = false;
                    break;
                } else s.pop();
        }
        if ( flag && s.empty() )
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
