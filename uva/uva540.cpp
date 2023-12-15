#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#define MAXL 8

using namespace std;

namespace GRP {
    static map<int, int> members;

    void add( int group, int id ) {
        members[id] = group;
        return;
    }

    int get( int id ) {
        return members[id];
    }

    void clear( void ) {
        members.clear();
        return;
    }
}

namespace QUE {
    static queue<int> que;
    static vector< queue<int> > groups;

    void resize( int group ) {
        groups.resize( group + 1 );
        return;
    }

    void push( int id ) {
        int group = GRP::get(id);
        if ( groups[group].empty() )
            que.push(group);
        groups[group].push(id);
        return;
    }

    int pop( void ) {
        if ( que.empty() )
            return -1;
        int popped = groups[que.front()].front();
        groups[que.front()].pop();
        if ( groups[que.front()].empty() )
            que.pop();
        return popped;
    }

    void clear( void ) {
        que = queue<int> ();
        groups.clear();
        return;
    }
}

int main( void ) {
#ifdef LOCAL
    freopen("uva540.in", "r", stdin);
    freopen("uva540.out", "w", stdout);
#endif
    int group, cnt = 0;
    while ( ~scanf("%d", &group) && group ) {
        for ( int i = 1; i <= group; i++ ) {
            int member;
            scanf("%d", &member);
            while ( member-- ) {
                int id;
                scanf("%d", &id);
                GRP::add(i, id);
            }
        }
        printf("Scenario #%d\n", ++cnt);
        QUE::resize(group);
        for ( ; ; ) {
            char cmd[MAXL];
            scanf("%s", cmd);
            if ( cmd[0] == 'E' ) {
                int id;
                scanf("%d", &id);
                QUE::push(id);
            } else if ( cmd[0] == 'S' ) {
                break;
            } else if ( cmd[0] == 'D' )
                printf("%d\n", QUE::pop());
        }
        printf("\n");
        GRP::clear();
        QUE::clear();
    }
    return 0;
}
