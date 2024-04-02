#include <iostream>
using namespace std;
const int N = 5e5 + 10;
typedef pair<bool, int> pir;
int main() {
    long long n, a[N] = {0}, d = 0, c = 1;
    long long ans = 0;
    char s[N];
    scanf("%lld%s", &n, s);
    bool l = s[0] == 'G';
    for ( int i = 1; i < n; i ++ )
        if ( ( s[i] == 'G' ) == l )
            c ++;
        else a[ ++ d ] = c, c = 1, l = s[i] == 'G';
    a[ ++ d ] = c;
    for ( int i = 1; i <= d; i ++ )
        ans += 0LL + ( a[i] == 1 ? a[ i - 1 ] * a[ i + 1 ] : 0 ) + ( a[i] - 1 ) * min( 1LL, a[ i + 1 ] ) + max( 0LL, a[ i + 1 ] - 1 );
    printf("%lld\n", ans);
    return 0;
}
