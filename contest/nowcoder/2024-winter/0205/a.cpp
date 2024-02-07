#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, K = 20;
int A[K], B[K];
int main() {
    int v;
    scanf("%d", &v);
    A[100] = 0;
    A[150] = 1;
    A[200] = 2;
    B[29] = 0;
    B[30] = 0;
    B[31] = 0;
    B[32] = 0;
    B[34] = 1;
    B[36] = 1;
    B[38] = 1;
    B[40] = 1;
    B[45] = 2;
    while ( v -- ) {
    	int a, b, c;
    	scanf("%d%d%d", &a, &b, &c);
    	printf("%d\n", A[a] + B[b] + B[c]);
    }
    return 0;
}
