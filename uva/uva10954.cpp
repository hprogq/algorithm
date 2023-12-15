#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n;
    while ( ~scanf("%d", &n) && n ) {
        int sum = 0;
        priority_queue< int, vector<int>, greater<int> > pq;
        for ( int i = 1; i <= n; i ++ ) {
            int t;
            scanf("%d", &t);
            pq.push(t);
        }
        while ( !pq.empty() ) {
            if ( pq.size() == 1 )
                break;
            int t1 = pq.top();  pq.pop();
            int t2 = pq.top();  pq.pop();
            sum += t1 + t2;
            pq.push( t1 + t2 );
        }
        printf("%d\n", sum);
    }
    return 0;
}
