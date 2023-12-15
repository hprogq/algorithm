#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int main() {
    int head = 0, tail = 0;
    int n, val[N], l[N], r[N], idx = 1;
    
    scanf("%d\n", &n);
    while ( n-- ) {
        char c, d;
        int k, x;
        scanf("%c", &c);
        
        if ( c == 'I' )
            scanf("%c %d %d\n", &d, &k, &x);
        else scanf(" %d\n", &k);
        
        if ( c == 'L' ) {
            val[idx] = k;
            l[idx] = 0;
            r[idx] = head;
            l[head] = idx;
            head = idx++;
            if ( !tail )
                tail = head;
        } else if ( c == 'R' ) {
            val[idx] = k;
            r[idx] = 0;
            l[idx] = tail;
            r[tail] = idx;
            tail = idx++;
            if ( !head )
                head = tail;
        } else if ( c == 'I' && d == 'L' ) {
            val[idx] = x;
            r[l[k]] = idx;
            l[idx] = l[k];
            r[idx] = k;
            l[k] = idx;
            if ( !l[idx] )
                head = idx;
            idx++;
        } else if ( c == 'I' && d == 'R' ) {
            val[idx] = x;
            l[r[k]] = idx;
            r[idx] = r[k];
            l[idx] = k;
            r[k] = idx;
            if ( !r[idx] )
                tail = idx;
            idx++;
        } else if ( c == 'D' ) {
            if ( !l[k] )
                head = r[k];
            if ( !r[k] )
                tail = l[k];
            r[l[k]] = r[k];
            l[r[k]] = l[k];
        }
    }
    
    int w = head;
    while ( w != 0 ) {
        printf("%d ", val[w]);
        w = r[w];
    }
    
    return 0;
}
