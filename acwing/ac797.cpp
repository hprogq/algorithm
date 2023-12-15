#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N] = {0}, b[N] = {0};

void insert(int l, int r, int c) {
    b[l] += c;
    b[ r + 1 ] -= c;
    return;
}

int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    
    for ( int i = 1; i <= n; i++ ) {
        int x;
        scanf("%d", &x);
        insert(i, i, x);
    }
    
    while ( m-- ) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    
    for ( int i = 1; i <= n; i++ ) {
        a[i] = a[ i - 1 ] + b[i];
        printf("%d ", a[i]);
    }
    
    return 0;
}
