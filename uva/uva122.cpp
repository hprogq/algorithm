#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int maxl = 300;

struct Node {
    int val;
    bool def = false;
    Node *left = NULL;
    Node *right = NULL;
};

Node* new_node() {
    return new Node();
}

bool add_node( Node *root, int val, const char *s ) {
    int len = strlen(s);
    Node *t = root;
    for ( int i = 0; i < len; i++ )
        if ( s[i] == 'L' )
            if ( ! t -> left )
                t = t -> left = new_node();
            else t = t -> left;
        else if ( s[i] == 'R' )
            if ( ! t -> right )
                t = t -> right = new_node();
            else t = t -> right;
    if ( t -> def )
        return false;
    t -> val = val;
    t -> def = true;
    return true;
}

int read_input( Node *root ) {
    char s[maxl];
    bool error = false;
    for ( ; ; ) {
        if ( !~scanf("%s", s) )
            return -1;
        if ( !strcmp( s, "()" ) )
            break;
        int val;
        sscanf(&s[1], "%d", &val);
        if ( !add_node( root, val, strchr(s, ',') + 1 ) )
            error = true;
    }
    return error;
}

bool bfs( Node *root, vector<int>& ans ) {
    queue< Node * > que;
    que.push(root);
    while ( !que.empty() ) {
        Node* temp = que.front();
        que.pop();

        if ( ! temp -> def )
            return false;
        
        ans.push_back( temp -> val );
        
        if ( temp -> left != nullptr )
            que.push( temp -> left );
        if ( temp -> right != nullptr )
            que.push( temp -> right );
    }
    return true;
}

void remove_tree( Node *node ) {
    if ( !node )
        return;
    remove_tree( node -> left );
    remove_tree( node -> right );
    delete node;
}

int main() {
#ifdef LOCAL
    freopen("uva122.in", "r", stdin);
    freopen("uva122.out", "w", stdout);
#endif

    for ( ; ; ) {
        Node *root = new_node();
        int r = read_input( root );
        if ( r == -1 )
            return 0;
        else if ( r == 1 )
            printf("not complete\n");
        else {
            vector<int> ans;
            if ( bfs(root, ans) )
                for ( auto it = ans.begin(); it != ans.end(); it++ )
                    printf("%d%c", *it, it == ans.end() - 1 ? '\n' : ' ');
            else printf("not complete\n");
        }
        remove_tree(root);
    }
    return 0;
}
