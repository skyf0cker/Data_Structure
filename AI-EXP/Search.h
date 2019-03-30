#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <iostream>
#include <vector>
#include <queue>
#include <alogrithm>

typedef struct TreeNode
{
    int **table;
    int i;
    int j;
    std::vector<struct TreeNode*> vec; 
    TreeNode(int **, int, int);
    TreeNode();
}Node, *node;

class Search
{
private:
    node root;
    int JudgeOver(int **);
    std::vector<node> open;
    std::vector<node> close;
    std::vector<int*> GetNeighboor(int, int);
    int computeH(int **);
    node MinFxNode();
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