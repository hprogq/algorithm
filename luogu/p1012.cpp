#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

bool cmp( const string& a, const string& b ) {
    return a > b;
}

int main() {
    vector<string> x;
    int n;
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) {
        int t;
        scanf("%d", &t);
        x.push_back( to_string(t) );
    }
    sort( x.begin(), x.end(), greater<string> () );
    for ( auto num : x )
        cout << num;
    cout << endl;
    return 0;
}