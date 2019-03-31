#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef struct TreeNode
{
    int **table;
    int i;
    int j;
    int g;
    int h;
    int f;
    struct TreeNode* parent;
    std::vector<struct TreeNode*> vec; 
    TreeNode(int **, int, int);
    TreeNode();
    int computeH();
}Node, *node;

class Search
{
private:
    node root;
    int JudgeOver(int **);
    std::vector<node> open;
    std::vector<node> close;
    std::vector<int*> GetNeighboor(int, int);
    node MinFxNode();
    void RemoveNode(node, std::vector<node>&);
    bool isIn(std::vector<int*> ,int*);
public:
    Search();
    void DFS(node&);
    void BFS(node&);
    void Astar(node&);
    friend node swap(node&, int, int);
    friend bool isInVec(node, std::vector<node>);
};

#endif