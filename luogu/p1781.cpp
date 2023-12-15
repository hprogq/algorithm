#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Candidate {
    int id;
    string bonus;

    Candidate ( int i, string s ) : id(i), bonus(s) {}
};

bool cmp( Candidate& a, Candidate& b ) {
    if ( a.bonus.length() != b.bonus.length() )
        return a.bonus.length() > b.bonus.length();
    return a.bonus > b.bonus;
}

int main() {
    int n;
    scanf("%d\n", &n);

    vector<Candidate> c;

    for ( int i = 1; i <= n; i++ ) {
        string s;
        getline( cin, s );
        c.push_back( Candidate(i, s) );
    }

    sort( c.begin(), c.end(), cmp );

    cout << c[0].id << endl << c[0].bonus << endl;
    
    return 0;
}
