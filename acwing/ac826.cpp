#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int n, val[N], next[N], idx = 1, head = -1;
    scanf("%d\n", &n);
    while ( n-- ) {
        char c;
        int k, x;
        scanf("%c", &c);
        
        if ( c == 'I' )
            scanf(" %d %d\n", &k, &x);
        else scanf(" %d\n", &k);
        
        if ( c == 'H' ) {
            val[idx] = k;
            next[idx] = head;
            head = idx++;
        } else if ( c == 'I' ) {
            val[idx] = x;
            next[idx] = next[k];
            next[k] = idx++;
        } else if ( c == 'D' ) {
            if ( k == 0 )
                head = next[head];
            else next[k] = next[ next[k] ];
        }
    }
    int w = head;
    while ( w != -1 ) {
        printf("%d ", val[w]);
        w = next[w];
    }
    return 0;
}
