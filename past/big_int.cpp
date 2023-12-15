#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

struct BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;

    BigInteger ( long long num = 0 ) {
        *this = num;
    }

    vector<int> s;
    BigInteger operator = ( long long num ) {
        s.clear();
        // use do...while to better use % and /
        do {
            s.push_back( num % BASE );
            num /= BASE;
        } while ( num > 0 );
        return *this;
    }

    BigInteger operator = ( const string& str ) {
        s.clear();
        int x, len = ( str.length() - 1 ) / WIDTH + 1;
        for ( int i = 0; i < len; i++ ) {
            int end = str.length() - i * WIDTH;
            int start = max ( 0, end - WIDTH );
            sscanf(str.substr(start, end - start).c_str(), "%d", &x); // turn string to stream, and read as integer to x
            s.push_back(x);
        }
        return *this;
    }

    BigInteger operator + ( const BigInteger& b ) {
        BigInteger c;
        c.s.clear();
        for ( int i = 0, g = 0; ; i++ ) {
            if ( g == 0 && i >= s.size() && i >= b.s.size() )
                break;
            int x = g;
            if ( i < s.size() )
                x += s[i];
            if ( i < b.s.size() )
                x += b.s[i];
            c.s.push_back( x % BASE );
            g = x / BASE;
        }
        return c;
    }

    BigInteger operator += ( const BigInteger& b ) {
        *this = *this + b;
        return *this;
    }

    bool operator > ( const BigInteger& b ) {
        if ( s.size() != b.s.size() )
            return s.size() < b.s.size();
        for ( int i = s.size() - 1 ; i >= 0; i-- )
            if ( s[i] != b.s[i] )
                return s[i] < b.s[i];
        return false;
    }
};

int main() {
    
    return 0;
}