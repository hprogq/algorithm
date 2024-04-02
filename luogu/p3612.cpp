#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
    string s;
    long long n;
    cin >> s >> n;
    while ( n > (int) s.length() ) {
        long long l = s.length() * ( 1LL << (int) log2( ( n - 1 ) / s.length() ) );
        n = (n - l) == 1 ? l : (n - l - 1);
    }
    printf("%c\n", s[ n - 1 ]);
    return 0;
}
