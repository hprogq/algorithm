#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int B = 4, L = 32;
struct Node {
    int type; // e: 0, p: 1, f: 2
    Node* sub[B];
};

int type( char c ) {
    switch ( c ) {
        case 'p': return 1;
        case 'f': return 2;
        case 'e': return 0;
    }
    return 0;
}

int create( Node *n, string& s, int i ) {
    int c = 0;
    n -> type = type( s[ i ++ ] );
    if ( n -> type == 1 ) {
        while ( c < B ) {
            Node* x = n -> sub[ c ++ ] = new Node();
            i = create( x, s, i++ );
        }
    }
    return i;
}

Node* input() {
    string s;
    getline( cin, s );
    Node *root = new Node();
    create( root, s, 0 );
    return root;
}

void output( Node* n, int& size, int length ) {
    if ( n -> type == 1 )
        for ( int i = 0; i < B; i++ )
            output( n -> sub[i], size, length / 2 );
    else if ( n -> type == 2 )
        size += length * length;
    return;
}

Node* copy( Node* x ) {
    Node* y = new Node();
    y -> type = x -> type;
    memcpy( y -> sub, x -> sub, sizeof( x -> sub ) );
    return y;
}

Node* merge( Node* a, Node* b ) {
    if ( a -> type == 2 || b -> type == 2 )
        return copy( a -> type == 2 ? a : b );
    else if ( a -> type + b -> type == 1 )
        return copy( a -> type == 1 ? a : b );
    else if ( a -> type + b -> type == 0 )
        return copy(a);
    else {
        Node* c = new Node();
        c -> type = 1;
        for ( int i = 0; i < B; i++ )
            c -> sub[i] = merge( a -> sub[i], b -> sub[i] );
        return c;
    }
}

void remove( Node *node ) {
    if ( node == nullptr )
        return;
    for ( int i = 0; i < B; i++ )
        remove( node -> sub[i] );
    delete node;
}

int main() {
#ifdef LOCAL
    freopen("uva297.in", "r", stdin);
    freopen("uva297.out", "w", stdout);
#endif
    int w;
    scanf("%d\n", &w);
    while ( w-- ) {
        int size = 0;
        Node *tree_1 = input();
        Node *tree_2 = input();
        Node *merged = merge( tree_1, tree_2 );
        output( merged, size, L );
        printf("There are %d black pixels.\n", size);
        remove( tree_1 );
        remove( tree_2 );
        remove( merged );
    }
}
