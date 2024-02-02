#include <iostream>
#include <cstdio>
#include <queue>
#include <cctype>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> stat;

int main() {
    int w, h, n;
    while ( ~scanf("%d %d %d\n", &w, &h, &n) && w ) {
        string alpha;
        for ( int i = 0; i < h; i ++ ) {
            for ( int j = 0; j < w; j ++ ) {
                char t;
                scanf("%c", &t);
                if ( isalpha(t) ) {
                    int apos = alpha.find( tolower(t) );
                    if ( apos == string::npos )
                        apos = alpha.append( 1, tolower(t) ).length() - 1;
                }
            }
        }
    }
    return 0;
}
