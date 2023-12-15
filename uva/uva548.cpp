#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

void create( Node *father, vector<int>& in, int in_l, int in_r, vector<int>& post, int post_l, int post_r, int& min_len, int& min_node, int len ) {
    father -> val = post[ post_r ];

    if ( in_l == in_r ) {
        // leaf
        len += father -> val;
        if ( len < min_len )
            min_len = len, min_node = father -> val;
        else if ( len == min_len )
            if ( father -> val < min_node )
                min_len = len, min_node = father -> val;
        return;
    }

    auto it = find( in.begin() + in_l, in.begin() + in_r + 1, father -> val );
    int f = distance( in.begin(), it );

    int l = f - in_l;
    int r = in_r - f;

    if ( l ) {
        father -> left = new Node();
        create( father -> left, in, in_l, f - 1, post, post_l, post_l + l - 1, min_len, min_node, len + father -> val );
    }

    if ( r ) {
        father -> right = new Node();
        create( father -> right, in, f + 1, in_r, post, post_l + l, post_r - 1, min_len, min_node, len + father -> val );
    }

    return;
}

void remove( Node *node ) {
    if ( !node )
        return;
    remove( node -> left );
    remove( node -> right );
    delete node;
}

int main() {
#ifdef LOCAL
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    string s1, s2;
    while ( getline( cin, s1 ) && getline( cin, s2 ) ) {
        string t1, t2;
        vector<int> in, post;
        stringstream ss1(s1), ss2(s2);
        while ( getline( ss1, t1, ' ' ) && getline( ss2, t2, ' ' ) )
            in.push_back( stoi(t1) ), post.push_back( stoi(t2) );
        int min_len = 0x7fffffff, min_node = -1;
        Node *root = new Node();
        create( root, in, 0, in.size() - 1, post, 0, post.size() - 1, min_len, min_node, 0 );
        printf("%d\n", min_node);
        remove( root );
    }
    return 0;
}
