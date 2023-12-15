#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div( vector<int>& a, int b, int& t ) {
    vector<int> c;
    for ( int i = 0; i < (int) a.size(); i++ ) {
        t = t * 10 + a[i];
        c.push_back( t / b );
        t %= b;
    }
    
    reverse( c.begin(), c.end() );
    while ( (int) c.size() > 1 && !c.back() )
        c.pop_back();
    
    return c;
} 

int main() {
    string A;
    int b, r = 0;
    vector<int> a;
    cin >> A >> b;
    for ( int i = 0; i < A.length(); i++ )
        a.push_back( A[i] - '0' );
    auto c = div( a, b, r );
    for ( int i = (int) c.size() - 1; i >= 0; i-- )
        printf("%d", c[i]);
    printf("\n%d\n", r);
    return 0;
}
