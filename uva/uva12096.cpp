#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <map>
#define MAXL 20
using namespace std;
typedef set<int> SET;
map<SET, int> set2id; //  set2id: set to id
vector<SET> id2set;  // id2set: id to set
stack<int> stak;   // stak: stack
void clear_stack() {
    while (!stak.empty()) {
        stak.pop();
    }
    return;
}
int uni_id( SET s ) {
    if ( set2id.count(s) )
        return set2id[s];
    id2set.push_back(s);
    return set2id[s] = id2set.size() - 1;
}
int main() {
#ifdef LOCAL
    freopen("uva12096.in", "r", stdin);
    freopen("uva12096.out", "w", stdout);
#endif
    int kase, oper;
    scanf("%d", &kase);
    while ( kase-- ) {
        scanf("%d", &oper);
        while ( oper-- ) {
            char com[MAXL];
            scanf("%s", com);
            if ( com[0] == 'P' )
                stak.push(uni_id(SET()));
            else if ( com[0] == 'D' )
                stak.push(stak.top());
            else {
                SET s1 = id2set[stak.top()];
                stak.pop();
                SET s2 = id2set[stak.top()];
                stak.pop();
                SET s;
                if ( com[0] == 'U' ) {
                    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s, s.begin()));
                    stak.push(uni_id(s));
                } else if ( com[0] == 'I' ) {
                    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s, s.begin()));
                    stak.push(uni_id(s));
                } else if ( com[0] == 'A' ) {
                    s = s2;
                    s.insert(set2id[s1]);
                    stak.push(uni_id(s));
                }
            }
            printf("%lu\n", id2set[stak.top()].size());
        }
        printf("***\n");
        set2id.clear();
        id2set.clear();
        clear_stack();
    }
    return 0;
}
