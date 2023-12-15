#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int y, m, d, mm, dd;
    scanf("%d%d", &mm, &dd);
    scanf("%d%d%d", &y, &m, &d);
    if ( d != dd )
        d ++;
    else if ( m != mm )
        m ++, d = 1;
    else y ++, m = d = 1;
    printf("%d %d %d", y, m, d);
    return 0;
}
