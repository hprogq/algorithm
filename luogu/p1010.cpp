#include <iostream>
#include <cmath>
using namespace std;

string spec[] = {
    "",
    "2(0)",
    "2",
    "2+2(0)"
};

string str(int n) {
    string a;
    int t = n, b;
    while (t) {
        if ( t <= 3 ) {
            a += spec[t];
            return a;
        } else b = log2(t), t -= 1 << b, a += "2(" + str(b) + ")" + ( t ? "+" : "" );
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", str(n).c_str());
    return 0;
}
