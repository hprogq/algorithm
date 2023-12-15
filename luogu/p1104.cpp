#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXL = 20;
struct Student {
    int id;
    int birth;
    char name[MAXL];
};

bool cmp( const Student& a, const Student& b ) {
    if ( a.birth != b.birth )
        return a.birth < b.birth;
    return a.id > b.id;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    vector<Student> s;
    for ( int i = 1; i <= n; i++ ) {
        Student temp;
        int y, m, d;
        temp.id = i;
        scanf("%s %d %d %d\n", temp.name, &y, &m, &d);
        temp.birth = y * 10000 + m * 100 + d;
        s.push_back(temp);
    }
    sort( s.begin(), s.end(), cmp );
    for ( auto item : s )
        printf("%s\n", item.name);
    return 0;
}