#include <vector>
#include <iostream>

typedef struct  TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int);
    TreeNode();
}Node, *node;

TreeNode::TreeNode(int val):data(val) {}
TreeNode::TreeNode() {}

class Search
{
private:
public:
    node root;
    Search();
    void PlanetTree(std::vector<int>);
    void BinSearch(int);
    void insert(int, node&);
    void Traversing(node);
};
