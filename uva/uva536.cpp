#include <iostream>
using namespace std;

string solve( string a, string b ) {
    char mid = a[0];
    int pos = b.find(mid);
    int llen = pos, rlen = a.length() - pos - 1;
    string laft = llen ? solve( a.substr( 1, llen ), b.substr( 0, llen ) ) : "";
    string raft = rlen ? solve ( a.substr( 1 + llen, rlen ), b.substr( 1 + llen, rlen ) ) : "";
    return laft + raft + mid;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin.tie(0);
    cout.tie(0);
    string a, b;
    while ( cin >> a >> b )
        cout << solve( a, b ) << endl;
    return 0;
}
