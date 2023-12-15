#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 310;

struct Student {
    int s[3];
    int t;
    int id;
    Student( int id, int a, int b, int c ) : t(a + b + c), id(id) {
        s[0] = a;
        s[1] = b;
        s[2] = c;
    }
};

bool cmp( const Student& a,  const Student& b ) {
    if ( a.t != b.t )
        return a.t > b.t;
    if ( a.s[0] != b.s[0] )
        return a.s[0] > b.s[0];
    return a.id < b.id;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector<Student> w;
    for ( int i = 1; i <= n; i++ ) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        w.push_back( Student(i, a, b, c) );
    }
    sort( w.begin(), w.end(), cmp );
    for ( int i = 0; i < 5; i++ )
        printf("%d %d\n", w[i].id, w[i].t);
    return 0;
}
