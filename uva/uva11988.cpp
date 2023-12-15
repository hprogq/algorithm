#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int main() {
    string input;
    while ( cin >> input ) {
        int last = 0, cur = 0;
        vector<int> next( input.length() + 1 );
        vector<char> ch;
        for ( int i = 0; i < input.length(); i++ ) {
            char c = input[i];
            if ( c == '[' )
                cur = 0;
            else if ( c == ']' )
                cur = ch.size();
            else {
                ch.push_back(c);
                int id = ch.size();
                if ( cur != id )
                    next[ id - 1 ] = id;
            }
        }
    }
}
