#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
int main() {
    int k;
    scanf("%d", &k);
    while ( k -- ) {
        int n;
        scanf("%d", &n);
        if ( !( n % 3 ) )
            printf("Second\n");
        else printf("First\n");
    }
    return 0;
}
