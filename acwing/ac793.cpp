#include <iostream>
#include <vector>
using namespace std;

vector<int> multi( vector<int>& a, int b ) {
    vector<int> c;
    int t = 0;
    for ( int i = 0; i < a.size() || t; i++ ) {
        if ( i < a.size() )  t += a[i] * b;
        c.push_back( t % 10 );
        t /= 10;
    }
    
    while ( c.size() > 1 && !c.back() )
        c.pop_back();
    
    return c;
}

int main() {
    string A;
    vector<int> a;
    int b;
    cin >> A >> b;
    for ( int i = A.length() - 1; i >= 0; i-- )
        a.push_back( A[i] - '0' );
    vector<int> c = multi(a, b);
    for ( int i = c.size() - 1; i >= 0; i-- )
        printf("%d", c[i]);
    return 0;
}
