#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
list<int> a;

vector<int> multi( vector<int>& a, int b ) {
    vector<int> c;
    int t = 0;
    for ( int i = 0; i < a.size() || t; i++ ) {
        if ( i < a.size() )  t = t + a[i] * b;
        c.push_back( t % 10 );
        t /= 10;
    }
    
    return c;
}

int main() {
    reverse(a.begin(), a.end());
    string A;
    vector<int> a;
    int b;
    for ( int i = A.length() - 1; i >= 0; i-- )
        a.push_back( A[i] );
    vector<int> c = multi(a, b);
    for ( int i = c.size(); i >= 0; i-- )
        printf("%d", c[i]);
    return 0;
}
