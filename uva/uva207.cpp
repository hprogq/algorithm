#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

// Global Config
const int Paid = 70, 
          Name = 20, 
          Half = 2,
          Round = 4, 
          Score = 3, 
          Player = 150;

// Player class as data.
struct player_class {
    string name;
    int id, rank;
    double money;
    vector<int> score;
    bool dq;
    int round;
    bool amateur;

    player_class() : score(Round + 1, 0) {}
};

// Print char 'c' 'n' times
void print_char( char c, int n ) {
    while ( n-- )
        printf("%c", c);
    return;
}

// Check if a player was Disqualified before "round"
bool if_dq_before( const player_class& player, const int round ) {
    return ( player.dq && player.round <= round );
}

// Sum the scores of a player from round begin to round end
int sum_score( const player_class& player, int begin, int end ) {
    int sum = 0;
    for ( int i = begin; i <= min( player.round, end ); i++ )
        sum += player.score[i] == -1 ? 0 : player.score[i];
    return sum;
}

// Compare: First 2 rounds
struct cmp_r1 {
    bool operator() ( const player_class& a, const player_class& b ) const {
        const int end = Half;
        if ( if_dq_before(a, end) ^ if_dq_before(b, end) )
            return !if_dq_before(a, end);
        else if (sum_score(a, 1, end) == sum_score(b, 1, end))
            return a.name.compare( b.name ) < 0;
        else return sum_score(a, 1, end) < sum_score(b, 1, end);
    }
};

// Compare: All 4 rounds
struct cmp_r2 {
    bool operator() ( const player_class& a, const player_class& b ) const {
        const int end = Round;
        if ( if_dq_before(a, end) ^ if_dq_before(b, end) )
            return !if_dq_before(a, end);
        else if ( a.round != b.round )
            return a.round > b.round;
        else if (sum_score(a, 1, end) == sum_score(b, 1, end))
            return a.name.compare( b.name ) < 0;
        else return sum_score(a, 1, end) < sum_score(b, 1, end);
    }
};

int main() {

#ifdef LOCAL
    freopen("uva207.in", "r", stdin);
    freopen("uva207.out", "w", stdout);
#endif

    // Role Num
    int rnd;
    scanf("%d\n", &rnd);

    while ( rnd-- ) {
        // Input money and rates
        double rate[ Paid + 1 ] = {0};
        double total_money;
        scanf("%lf", &total_money);
        for ( int i = 1; i <= Paid; i++ )
            scanf("%lf\n", &rate[i]);

        // Player Num
        int player;
        scanf("%d\n", &player);

        // Vector to all players
        vector<player_class> players( player + 1 );

        // Input and Store
        for ( int i = 1; i <= player; i++ ) {
            // Temp rounds
            int t = 0;

            // Store A single input Line
            string s;
            getline(cin, s);

            // Self-Increase ID
            players[i].id = i;

            // Initial, also can be used in struct after C++
            players[i].dq = false;
            players[i].round = Round;
            players[i].amateur = false;

            // First 20 chars
            players[i].name = s.substr( 0, s.substr(0, Name).find_last_not_of(' ') + 1 );

            // If Amateur
            players[i].amateur = ( players[i].name[ players[i].name.length() - 1 ] == '*' );

            // Read Score, using do ... while 'cause at least 1 score
            do {
                if ( ++t > Round )
                    break;
                
                // Temp String of the t round
                string tmps = s.substr(Name + (t - 1) * Score, Score);

                if ( tmps[ tmps.length() - 1 ] == 'Q' || tmps[ tmps.length() - 2 ] == 'Q' || tmps[ tmps.length() - 3 ] == 'Q' ) {
                    // Disqualified
                    players[i].round = t;
                    players[i].score[t] = -1;
                    players[i].dq = true;
                } else players[i].score[t] = stoi( tmps.substr( tmps.find_first_not_of(' '), tmps.length() - tmps.find_first_not_of(' ') ) ); // Store the score
            } while ( !players[i].dq );
        }

        // Half Round Cal
        sort( players.begin() + 1, players.end(), cmp_r1() );
        int dq_half = 0;
        for ( int i = 1; i <= player; i++ )
            if ( if_dq_before( players[i], Half ) )
                dq_half++;
        int half_num = min( player - dq_half, Paid );
        int half_score = sum_score(players[half_num], 1, Half);
        while ( half_num + 1 < player && sum_score( players[ half_num + 1 ], 1, Half ) == half_score ) // Get Same Score
            half_num++;
        
        // End Round Cal
        sort( players.begin() + 1, players.begin() + half_num + 1, cmp_r2() );

        // Get Rank
        vector<int> same_rank( Player + 1, 0 );
        int last_rank = -1, last_score = -1;
        for ( int i = 1; i <= half_num; i++ ) {
            if ( sum_score( players[i], 1, Round ) != last_score ) {
                last_rank = i;
                last_score = sum_score( players[i], 1, Round );
                players[i].rank = i;
            } else players[i].rank = last_rank;
            if ( !players[i].amateur )
                same_rank[ players[i].rank ]++;
        }
        
        // Calculate Money
        int place = 1, left_place = 0;
        bool stop = false;
        double last_money = -1;
        for ( int i = 1; i <= half_num && !stop; i++ ) {
            if ( players[i].amateur || players[i].dq )
                players[i].money = -1;
            else if ( left_place ) {
                left_place--;
                players[i].money = last_money;
            } else {
                // Tie but not others
                if ( place > Paid ) {
                    players[i].money = -2;
                    stop = true;
                } else {
                    left_place = same_rank[ players[i].rank ] - 1;
                    double total_rank = 0;
                    for ( int j = place; j <= place + same_rank[ players[i].rank ] - 1; j++ )
                        total_rank += j > Paid ? 0 : rate[j];
                    // Important
                    last_money = players[i].money = total_money * total_rank / same_rank[ players[i].rank ] / 100.0;
                    place += same_rank[ players[i].rank ];
                }
            }
        }

        // Output
        printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n-----------------------------------------------------------------------\n");

        stop = false;
        for ( int i = 1; i <= half_num; i++ ) {
            stop = stop ? stop : players[i].money == -2;
            // Name for 21 chars
            cout << setw(21) << left << players[i].name;
            // Two or more person have a same rank ( without amateurs ) will have a 'T'
            if ( !players[i].dq )
                cout << setw(10) << left << ( to_string( players[i].rank ) + ( ( !players[i].amateur && players[i].money > -1 && !stop && same_rank[ players[i].rank ] > 1 ) ? "T" : "" ) );
            else printf("          ");
            // Score Printing
            for ( int j = 1; j <= Round; j++ )
                if ( j <= players[i].round && players[i].score[j] != -1 )
                    printf("%-5d", players[i].score[j]);
                else printf("     ");
            // Total Score Printing
            if ( !players[i].amateur && !players[i].dq && !stop )
                printf( "%-10d", sum_score( players[i], 1, Round ) );
            else if ( players[i].dq && stop )
                printf("DQ");
            else if ( !players[i].dq )
                printf( "%d", sum_score( players[i], 1, Round ) );
            else printf("DQ");
            if ( !players[i].amateur && !players[i].dq && !stop )
                printf( "$%9.2lf", players[i].money );
            // End of one player
            printf("\n");
        }
        if ( rnd )
            printf("\n");
    }
    return 0;
}
