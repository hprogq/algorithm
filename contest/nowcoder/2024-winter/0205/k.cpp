#include <iostream>
#include <cmath>
#include <set>
using namespace std;

string replaceChars(string str, int a, int b, int c, int d, int u) {
    string ne = str;
    for (char& ch : ne) {
        switch (ch) {
            case 'a':
                ch = '0' + a;
                break;
            case 'b':
                ch = '0' + b;
                break;
            case 'c':
                ch = '0' + c;
                break;
            case 'd':
                ch = '0' + d;
                break;
            case '_':
                ch = '0' + u;
                break;
            default:
                break;
        }
    }
    return ne;
}

bool check_valid(int n, int s, int y) {
    return s <= y && s >= ( n == 1 ? 0 : pow(10, n - 1)) && !(s % 8);
}

int main() {
    int v;
    cin >> v;
    while ( v -- ) {
        int a, b, c, d, u;
        set<int> vis;
        int n;
        string str;
        int y;
        cin >> n >> str >> y;
        for ( a = 0; a <= 9; a ++ )
            for ( b = 0; b <= 9; b ++ )
                for ( c = 0; c <= 9; c ++ )
                    for ( d = 0; d <= 9; d ++ )
                        for ( u = 0; u <= 9; u ++ ) {
                            if ( a == b || a == c || a == d || b == c || b == d || c == d )
                                continue;
                            int p = stoi(replaceChars(str, a, b, c, d, u));
                            if ( vis.find(p) == vis.end() && check_valid( n, p, y ) )
                                vis.insert(p);
                        }
        // cout << *vis.begin() << "\n\n";
        cout << vis.size() << "\n";
    }
}