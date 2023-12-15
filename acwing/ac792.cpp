#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair< bool, vector<int> > bint;

bool cmp( string& a, string& b ) {
    if ( a.length() != b.length() )
        return a.length() > b.length();
    else return a >= b;
}

bint sub( string& a, string& b) {
    vector<int> x, y, z;
    for ( int i = a.length() - 1; i >= 0; i-- )
        x.push_back( a[i] - '0' );
    for ( int i = b.length() - 1; i >= 0; i-- )
        y.push_back( b[i] - '0' );
    
    bool p = cmp( a, b );
    if ( !p )  swap( x, y );
    
    for ( int i = 0, t = 0; i < (int) x.size(); i++ ) {
        t = t + x[i] - ( i < (int) y.size() ? y[i] : 0 );
        z.push_back( ( t + 10 ) % 10 );
        if ( t < 0 )  t = -1;
        else t = 0;
    }

    while ( z.size() > 1 && !z.back() )
        z.pop_back();
    
    return bint(p, z);
}

int main() {
    string a, b;
    cin >> a >> b;
    bint c = sub( a, b );
    printf("%s", c.first ? "" : "-");
    for ( int i = c.second.size() - 1; i >= 0; i-- )
        printf("%d", c.second[i]);
    return 0;
}
