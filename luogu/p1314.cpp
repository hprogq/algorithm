#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;

int find( vector<int>& a, int x ) {
    int l = 0, r = a.size() - 1;
    while ( l < r ) {
        int mid = ( l + r ) >> 1;
        if ( a[mid] >= x )  r = mid;
        else l = mid + 1;
    }
    return r;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    long long s, sa[N] = {0}, sb[N] = {0};
    vector< pair<int, int> > insert, query;
    scanf("%d%d%lld", &n, &m, &s);

    vector<int> all;
    for ( int i = 1; i <= n; i++ ) {
        int x, y;
        scanf("%d%d", &x, &y);
        all.push_back( x );
        insert.push_back( make_pair( x, y ) );
    }

    for ( int i = 1; i <= m; i++ ) {
        int l, r;
        scanf("%d%d", &l, &r);
        all.push_back( l );
        all.push_back( r );
        query.push_back( make_pair( l, r ) );
    }
    
    sort( all.begin(), all.end() );
    all.erase( unique( all.begin(), all.end() ), all.end() );

    vector<int> a( all.size() + 1 ), b( all.size() + 1 );

    for ( auto item : insert ) {
        a[ find( all, item.first ) ] ++;
        b[ find( all, item.first ) ] += item.second;
    }

    for ( int i = 1; i < all.size(); i++ ) {
        sa[i] = sa[ i - 1 ] + a[i];
        sb[i] = sb[ i - 1 ] + b[i];
    }


    int l = 1, r = all.size() - 1;
    long long ans = 1e14;
    while( l < r ) {
        int mid = ( l + r + 1 ) >> 1;
        long long ss = 0;
        for ( auto item : query )
            if ( item.first >= mid && item.second >= mid )
                ss += ( sa[ max( mid, find ( all, item.second ) ) ] - sa[ max( mid, find ( all, item.first ) ) - 1 ] ) * ( sb[ max( mid, find ( all, item.second ) ) ] - sb[ max( mid, find ( all, item.first ) ) - 1 ] );
        if( ss > s )
            l = mid;
        else r = mid - 1;
        if( abs( ss - s ) < ans ) ans = abs( ss - s );
	}

    printf("%lld\n", ans);
    return 0;
}
