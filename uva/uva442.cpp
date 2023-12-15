#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

#define LEFT -1
#define RIGHT -2

using namespace std;

struct Matrix {
    int a, b;
};

int main() {
#ifdef LOCAL
    freopen("uva442.in", "r", stdin);
    freopen("uva442.out", "w", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    vector<Matrix> m(27);
    for ( int i = 1; i <= n; i++ ) {
        char c;
        int a, b;
        scanf("%c %d %d\n", &c, &a, &b);
        m[ c - 'A' + 1 ].a = a;
        m[ c - 'A' + 1 ].b = b;
    }
    string exp;
    while ( cin >> exp ) {
        int time = 0;
        stack<int> s;
        bool flag = true;
        for ( int i = 0; i < exp.length() && flag; i++ ) {
            if ( exp[i] == '(' )
                s.push( LEFT );
            else if ( exp[i] == ')' ) {
                Matrix b = m[ s.top() ];
                s.pop();
                Matrix a = m[ s.top() ];
                s.pop();
                s.pop();
                if ( a.b != b.a )
                    flag = false;
                else {
                    Matrix t;
                    t.a = a.a;
                    t.b = b.b;
                    m.push_back(t);
                    s.push( m.size() - 1 );
                    time += a.a * a.b * b.b;
                }
            } else {
                s.push( exp[i] - 'A' + 1 );
            }
        }
        if ( flag )
            printf("%d\n", time);
        else printf("error\n");
    }
    return 0;
}
