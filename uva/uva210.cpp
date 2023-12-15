#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <deque>
using namespace std;

struct command {
    /*  type
        1: var = constant
        2: print var
        3: lock
        4: unlock
        5: end
    */
    int type = 0;
    int a = 0, b = 0;
};

command new_command( int type, int a = 0, int b = 0 ) {
    command cmd;
    cmd.type = type;
    cmd.a = a;
    cmd.b = b;
    return cmd;
}

int main() {

#ifdef LOCAL
    freopen("uva210.in", "r", stdin);
    freopen("uva210.out", "w", stdout);
#endif

    int kase;
    scanf("%d\n", &kase);

    while ( kase-- ) {
        int n, tcost[6], v[27] = {0}, q;
        scanf("\n%d%d%d%d%d%d%d", &n, &tcost[1], &tcost[2], &tcost[3], &tcost[4], &tcost[5], &q);
        vector< queue<command> > cmds( n + 1 );
        deque<int> que;
        queue<int> ban_que;
        for ( int i = 1; i <= n; i++ )
            que.push_back(i);
        for ( int i = 1; i <= n; ) {
            string cmd;
            getline(cin, cmd);
            if ( cmd.find('=') != string::npos ) {
                // var
                int constant = stoi( cmd.substr( cmd.find('=') + 2, cmd.length() - cmd.find('=') - 2 ) );
                cmds[i].push( new_command( 1, cmd[0] - 'a' + 1, constant ) );
                // v[var] = constant;
                // printf("%d %d\n", var, constant);
            } else if ( cmd[0] == 'p' ) {
                // print
                cmds[i].push( new_command( 2, cmd[6] - 'a' + 1 ) );
            } else if ( cmd[0] == 'l' ) {
                // lock
                cmds[i].push( new_command(3) );
            } else if ( cmd[0] == 'u' ) {
                // unlock
                cmds[i].push( new_command(4) );
            } else if ( cmd[0] == 'e' ) {
                // end
                cmds[i].push( new_command(5) );
                i++;
            }
        }
        bool lock = false;
        while ( !que.empty() ) {
            int p = que.front();
            int time = q;
            bool end = false, ban = false;

            que.pop_front();
            
            while ( !end && !ban && time > 0 ) {
                command t = cmds[p].front();
                int ttime = tcost[t.type];
                bool pop = true;

                time -= ttime;

                if ( t.type == 1 )
                    v[ t.a ] = t.b;

                if ( t.type == 2 )
                    printf("%d: %d\n", p, v[ t.a ]);

                if ( t.type == 3 ) {
                    if ( lock )
                        end = true, ban = true, pop = false;
                    else lock = true;
                }

                if ( t.type == 4 ) {
                    lock = false;
                    if ( !ban_que.empty() ) {
                        que.push_front( ban_que.front() );
                        ban_que.pop();
                    }
                }

                if ( t.type == 5 )
                    end = true;
                
                if ( pop )
                    cmds[p].pop();

            }

            if ( ban )
                ban_que.push(p);

            if ( !end )
                que.push_back(p);

        }
        if ( kase )
            printf("\n");
    }
    return 0;
}
