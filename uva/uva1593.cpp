#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
const int maxl = 1000 + 10, maxw = 180 + 10;
int main() {
#ifdef LOCAL
    freopen("uva1593.in", "r", stdin);
    freopen("uva1593.out", "w", stdout);
#endif
    string s;
    vector<string> words[maxl];
    vector<int> len(maxw);
    int row = 0;
    while ( getline(cin, s) ) {
        row++;
        stringstream ss(s);
        string t;
        while ( ss >> t ) {
            words[row].push_back(t);
            len[ words[row].size() ] = max( len[ words[row].size() ], (int) t.length() + 1 );
        }
    }
    for ( int i = 1; i <= row; i++ ) {
        int cnt = words[i].size();
        for ( int j = 0; j < cnt; j++ ) {
            cout << words[i][j];
            int blank = len[ j + 1 ] - words[i][j].length();
            if ( j != cnt - 1 )
                for ( int k = 1; k <= blank; k++ )
                    printf(" ");
        }
        printf("\n");
    }
    return 0;
}
