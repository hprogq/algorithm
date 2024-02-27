#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pir;
const int N = 2e5 + 10;
int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int v;
    scanf("%d", &v);
    while ( v -- ) {
        string a, b;
        cin >> a >> b;
        if ( tolower(a[0]) == tolower(b[0]) )
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
