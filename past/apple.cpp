#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int between = 2;
int main() {
    int num;
    scanf("%d", &num);
    vector<bool> apple( num + 1, false );
    int temp = 0, total = 1, num_taken, taken = 0;
    for ( int i = 1; taken != num ;  ) {
        if ( !apple[i] && !temp-- ) {
            taken++;
            apple[i] = true;
            temp = between;
            if ( i == num )
                num_taken = total;
        }
        if ( taken != num && i == num ) {
            i = 1, temp = 0, total++;
        } else i++;
    }
    printf("%d %d\n", total, num_taken);
    return 0;
}
