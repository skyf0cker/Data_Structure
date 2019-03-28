#include "Search.h"

using namespace std;

Search::Search() {
    this->root = new Node(0);
}

void Search::Traversing(node n) {
    if (n != NULL) {
        cout<<n->data<<endl;
        Traversing(n->left);
        Traversing(n->right);
    }
}

void Search::BinSearch(int val) {
    node n = root;
    while(n){
        if (n->data > val) {
            n = n->left;
        } else if (n->data < val)
        {   
            n = n->right;
        } else
        {
            cout<<"FOUND IT!"<<endl;
            return;
        }
    }
    cout<<"NOT FOUND!"<<endl;
}

void Search::insert(int val, node &n) {
    if (not n) {
        n = new Node(val);
    } else {
        if (val > n->data) {
            insert(val, n->right);
        } else {
            insert(val, n->left);
        }
    }
}

void Search::PlanetTree(vector<int> vec) {
    for (int i:vec) {
        insert(i, root);
    }
}

int main() {
    Search s;
    vector<int> vec({1,2,4,5,6,8});
    s.PlanetTree(vec);
    // s.Traversing(s.root);
    s.BinSearch(5);
}