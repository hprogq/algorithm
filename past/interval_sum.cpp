#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find( vector<int>& a, int k ) {
    int l = 0, r = a.size() - 1;
    while ( l < r ) {
        int mid = ( l + r ) >> 1;
        if ( a[mid] >= k )  r = mid;
        else l = mid + 1;
    }
    return r;
}

int main() {
    vector<int> all;
    vector< pair<int, int> > insert, query;

    int n, m;
    scanf("%d%d", &n, &m);
    
    for ( int i = 1; i <= n; i++ ) {
        int x, c;
        scanf("%d%d", &x, &c);
        all.push_back(x);
        
        insert.push_back( make_pair( x, c ) );
    }
    
    for ( int i = 1; i <= m; i++ ) {
        int l, r;
        scanf("%d%d", &l, &r);
        all.push_back(l);
        all.push_back(r);
        
        query.push_back( make_pair( l, r ) );
    }
    
    sort( all.begin(), all.end() );
    all.erase( unique( all.begin(), all.end() ), all.end() );
    
    vector<int> a( all.size() + 1, 0 ), s( all.size() + 1, 0 );
    
    for ( auto item : insert )
        a[ find( all, item.first ) + 1 ] += item.second;
    
    for ( int i = 1; i <= (int) a.size(); i++ )
        s[i] = s[ i - 1 ] + a[i];
    
    for ( auto item : query )
        printf("%d\n", s[ find( all, item.second ) + 1 ] - s[ find( all, item.first )  ]);
    
    return 0;
}
