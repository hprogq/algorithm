#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define MAXL 18
#define ITER(x) x.begin(),x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

namespace ID {
    static map< set<int>, int > set2id;
    static vector< set<int> >   id2set;

    static int gen( set<int>& s ) {
        if ( set2id.count(s) )
            return set2id.at(s);
        id2set.push_back(s);
        return set2id[s] = id2set.size() - 1;
    }
    static void clear() {
        set2id.clear();
        id2set.clear();
    }
}

int main() {
#ifdef LOCAL
    freopen("uva12096.in", "r", stdin);
    freopen("uva12096.out", "w", stdout);
#endif
    int kase;
    scanf("%d", &kase);
    while ( kase-- ) {
        int oper;
        scanf("%d", &oper);
        stack<int> stak;
        while ( oper-- ) {
            char com[MAXL];
            scanf("%s", com);
            set<int> s;

            if ( com[0] == 'P' )
                stak.push( ID::gen(s) );
            else if ( com[0] == 'D' )
                stak.push( stak.top() );
            else {
                set<int> s1 = ID::id2set.at( stak.top() );
                stak.pop();
                set<int> s2 = ID::id2set.at( stak.top() );
                stak.pop();

                if ( com[0] == 'U' )
                    set_union( ITER(s1), ITER(s2), INS(s) );
                else if ( com[0] == 'I' )
                    set_intersection( ITER(s1), ITER(s2), INS(s) );
                else if ( com[0] == 'A' ) {
                    s = s2;
                    s.insert(ID::gen(s1));
                }

                stak.push( ID::gen(s) );
            }

            printf( "%lu\n", ID::id2set.at( stak.top() ).size() );
        }
        printf("***\n");
        ID::clear();
    }
    return 0;
}
