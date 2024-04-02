#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef pair<int, int> frac;

int main() {
    int n;
    vector<frac> s;
    scanf("%d", &n);
    s.push_back( frac( 0, 1 ) );
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= i; j ++ )
            if ( gcd( i, j ) == 1 )
                s.push_back( frac( j, i ) );
    sort( s.begin(), s.end(), []( const frac& a, const frac& b ) {
        return a.first * b.second < a.second * b.first;
    } );
    for ( auto e : s )
        printf("%d/%d\n", e.first, e.second);
    return 0;
}
