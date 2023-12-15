#include <iostream>
#include <cmath>
using namespace std;

int turn( int d ) {
    return d ? d : 10;
}

int solve( int x ) {
    int a = x / 1000, b = x / 100 % 10, c = x / 10 % 10, d = x % 10;
    return abs( turn(a) - 1 ) + abs( turn(b) - turn(a) ) + abs( turn(c) - turn(b) ) + abs( turn(d) - turn(c) ) + 4;
}

int main() {
    int n;
    scanf("%d", &n);
    while ( n-- ) {
        int x;
        scanf("%d", &x);
        printf("%d\n", solve(x));
    }
    return 0;
}