#include <iostream>
#include <queue>
#include <set>
#include <cstdio>
#define LEN 3
using namespace std;
const int x[3] = {2, 3, 5};
int main() {
    priority_queue< long long, vector<long long>, greater<long long> > q;
    set<long long> s;
    q.push(1);
    s.insert(1);
    bool e = false;
    for ( int i = 1; ; i++ ) {
        long long t = q.top();
        q.pop();
        if ( i == 1500 ) {
            printf("The 1500'th ugly number is %lld.\n", t);
            break;
        }
        for ( int i = 0; i < LEN; i++) {
            long long n = t * x[i];
            if ( !s.count(n) ) {
                q.push(n);
                s.insert(n);
            }
        }
    }
    return 0;
}
