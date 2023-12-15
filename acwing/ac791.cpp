#include <iostream>
#include <vector>
using namespace std;

vector<int> add( vector<int>& a, vector<int> &b ) {
    int t = 0;
    vector<int> c;
    for ( int i = 0; i < (int) a.size() || i < (int) b.size(); i++ ) {
        if ( i < (int) a.size() )  t += a[i];
        if ( i < (int) b.size() )  t += b[i];
        c.push_back( t % 10 );
        t /= 10;
    }
    if ( t )
        c.push_back(t);
    return c;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> x, y;
    for ( int i = a.length() - 1; i >= 0; i-- )  x.push_back( a[i] - '0' );
    for ( int i = b.length() - 1; i >= 0; i-- )  y.push_back( b[i] - '0' );
    
    auto ans = add(x, y);
    for ( int i = ans.size() - 1; i >= 0; i-- )
        printf("%d", ans[i]);
    return 0;
}
