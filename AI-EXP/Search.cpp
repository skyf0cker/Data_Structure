#include "Search.h"

using namespace std;

node swap(node &n, int i, int j) {
    if ((abs(n->i - i) == 1 and j == n->j) or (abs(n->j - j) == 1 and i == n->i)) {
        int **out_table = new int*[3];
        for (int _i=0;_i<3;_i++) {
            out_table[_i] = new int[3];
            for (int _j=0;_j<3;_j++) {
                out_table[_i][_j] = n->table[_i][_j];
            }
        }
        int temp = out_table[n->i][n->j];
        out_table[n->i][n->j] = out_table[i][j];
        out_table[i][j] = temp;
        node out_node = new Node(out_table, i, j);
        return out_node;
    } else
    {
        cout<<"wrong pos:"<<i<<","<<j<<endl;
        cerr<<"ERROR:POSITION WRONG!!!"<<endl;
        return NULL;
    }
}

Search::Search() {
    root = new Node();
    cout<<"[*]:the following are DFS process"<<endl;
    DFS(root);
    BFS(root);
    Astar(root);
}

vector<int*> Search::GetNeighboor(int i, int j) {
    vector<int*> result;
    if ((i == j and i*j != 1) or (i+j==2 and i*j != 1)) {
        int *a = new int[2];
        int *b = new int[2];
        int A[2] = {abs(i-1), j};
        int B[2] = {i, abs(j-1)};
        for (int _ = 0;_ < 2;_++) {
            a[_] = A[_];
            b[_] = B[_];
        }
        result.push_back(a);
        result.push_back(b);
    } else if (i*j == 1){
        int *a = new int[2];
        int *b = new int[2];
        int *c = new int[2];
        int *d = new int[2];

        int A[2] = {i-1, j};
        int B[2] = {i+1, j};
        int C[2] = {i, j+1};
        int D[2] = {i, j-1};

        for (int _ = 0;_ < 4;_++) {
            a[_] = A[_];
            b[_] = B[_];
            c[_] = C[_];
            d[_] = D[_];
        }

        result.push_back(a);
        result.push_back(b);
        result.push_back(c);
        result.push_back(d);
    } else {
        if ((i == 0 and j == 1) or (i == 2 and j == 1)) {
            int *a = new int[2];
            int *b = new int[2];
            int *c = new int[2];

            int A[2] = {i, j+1};
            int B[2] = {i, j-1};
            int C[2] = {abs(i-1), j};
            
            for (int _ = 0;_ < 3;_++) {
                a[_] = A[_];
                b[_] = B[_];
                c[_] = C[_];
            }

            result.push_back(a);
            result.push_back(b);
            result.push_back(c);
        } else {
            int *a = new int[2];
            int *b = new int[2];
            int *c = new int[2];

            int A[2] = {i+1, j};
            int B[2] = {i-1, j};
            int C[2] = {i, abs(j-1)};

            for (int _ = 0;_ < 3;_++) {
                a[_] = A[_];
                b[_] = B[_];
                c[_] = C[_];
            }
            result.push_back(a);
            result.push_back(b);
            result.push_back(c);
        }
    }
    return result;
}

bool Search::isIn(vector<int*> path,int *check) {
    for(int* _check:path) {
        if (_check[0] == check[0] and _check[1] == check[1]) {
            return true;
        } else
        {
            continue;
        }
    }
    return false;
}

void Search::BFS(node &n) {
    cout<<"[*]:the following are BFS process"<<endl;
    queue<node> que;
    que.push(n);
    while(true) {
        node temp = que.front();
        que.pop();
        cout<<"trying :"<<temp->i<<","<<temp->j<<endl;
        if (JudgeOver(temp->table)) {
            cout<<"SUCCESS!"<<endl;
            return;
        } else {
            for (node m:temp->vec) {
                que.push(m);
            }
        }
    }
}

void Search::DFS(node &n) {
    if (n->parent) {
        n->g = n->parent->g + 1;
        n->h = n->computeH();
        n->f = n->g + n->h;
    } else {
        n->g = 0;
        n->h = n->computeH();
        n->f = n->g + n->h;
    }
    
    if (JudgeOver(n->table)) {
        cout<<"SUCCESS"<<endl;
        return;
        // exit(0);
    } else {
        cout<<"current pos:"<<n->i<<","<<n->j<<endl;
        vector<int*> neighbor = GetNeighboor(n->i, n->j);
        int *root_pos = new int[2];
        root_pos[0] = n->i;
        root_pos[1] = n->j;
        int vec_size = neighbor.size();
        // for (int s=0;s<vec_size;s++) {
        //     cout<<"pos:"<<neighbor[s][0]<<","<<neighbor[s][1]<<endl;
        // }
        static vector<int*> *path = new vector<int*>({root_pos});
        // cout<<(*path)[0][1]<<endl;
        for (int i = 0;i<vec_size;i++) {
            if (isIn(*path, neighbor[i])) {
                // cout<<"jump pos:"<<neighbor[i][0]<<","<<neighbor[i][1]<<endl;
                // cout<<"got it"<<endl;
                continue;
            } else
            {
                // cout<<"insert pos:"<<neighbor[i][0]<<","<<neighbor[i][1]<<endl;                
                path->push_back(neighbor[i]);
            }
            // cout<<"params:"<<neighbor[i][0]<<","<<neighbor[i][1]<<endl;
            node temp = swap(n, neighbor[i][0], neighbor[i][1]);
            n->vec.push_back(temp);
            temp->parent = n;
            DFS(temp);
            // cout<<path->size()<<endl;
            int *del = *(path->end()-1);
            // cout<<"del pos:"<<del[0]<<","<<del[1]<<endl;
            path->pop_back();
        }
    }
}

int TreeNode::computeH() {
    return abs(table[0][0] - 1) + abs(table[0][1] - 2) + abs(table[0][2] - 3) + abs(table[1][0] - 8) + abs(table[1][1] - 0) + abs(table[1][2] - 4) + abs(table[2][0] - 7) + abs(table[2][1] - 6) + abs(table[2][2] - 5);
}

node Search::MinFxNode() {
    int Min = 100000;
    int fx = 0;
    for (node n:open) {
        if (not n->parent) {
            fx = n->computeH();
        } else {
            fx = n->computeH() + n->parent->g + 1;
        }
        n->f = fx;
        Min = min(fx, Min);
    }
    for (int i=0;i<open.size();i++) {
        node n = open[i];
        if (Min == n->computeH() + n->g) {
            return n;
        }
    }
}

bool isInVec(node i, vector<node> vec) {
    for (node _t:vec) {
        if (_t == i) {
            return true;
        }
    }
    return false;
}

void Search::RemoveNode(node n, vector<node> &vec) {
    for (int i=0;i<vec.size();i++) {
        if (n == vec[i]) {
            vec.erase(vec.begin()+i);
        }
    }
}

void Search::Astar(node &n) {
    cout<<"--------Astar-------"<<endl;
    open.push_back(n);
    while(not open.empty()){
        node minNode = MinFxNode();
        // for (int x=0;x<3;x++) {
        //     for (int y=0;y<3;y++) {
        //         cout<<minNode->table[x][y];
        //     }
        //     cout<<endl;
        // }
        // cout<<"-------------------"<<endl;
        RemoveNode(minNode, open);
        close.push_back(minNode);

        if (JudgeOver(minNode->table)) {
            cout<<"SUCCESS!"<<endl;
            cout<<"PATH:"<<endl;
            cout<<"---------------"<<endl;

            while(minNode->parent){
                for (int x=0;x<3;x++) {
                   for (int y=0;y<3;y++) {
                        cout<<minNode->table[x][y];
                    }
                    cout<<endl;
                }
                cout<<"---------------"<<endl;
                minNode = minNode->parent;    
            }
            
            return;
        } else {
            for (node _n:minNode->vec) {
                _n->f = _n->parent->g+1+_n->computeH();
                if (not (isInVec(_n, close) or isInVec(_n, open))) {
                    open.push_back(_n);
                } else {
                    if (_n->f < minNode->f) {
                        minNode = _n;
                        if (isInVec(minNode, close)) {
                            RemoveNode(minNode, close);
                            open.push_back(minNode);
                        }
                    }
                }
                
            }
        }      

    }
}

int Search::JudgeOver(int **table) {
    for (int i=0;i<3;i++) {
        if (i == 0) {
            for (int j=0;j<3;j++) {
                switch (j)
                {
                    case 0:{
                        if (table[i][j] != 1) {
                           return 0;
                        }
                        break;
                    }
                    case 1:{
                        if (table[i][j] != 2) {
                            return 0;
                        }
                        break;
                    }
                    case 2:{
                        if (table[i][j] != 3) {
                            return 0;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        if (i == 1) {
            for (int j=0;j<3;j++) {
                switch (j)
                {
                    case 0:{
                        if (table[i][j] != 8) {
                            return 0;
                        }
                        break;
                    }
                    case 1:{
                        if (table[i][j] != 0) {
                            return 0;
                        }
                        break;
                    }
                    case 2:{
                        if (table[i][j] != 4) {
                            return 0;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        if (i == 2) {
            for (int j=0;j<3;j++) {
                switch (j)
                {
                    case 0:{
                        if (table[i][j] != 7) {
                            return 0;
                        }
                        break;
                    }
                    case 1:{
                        if (table[i][j] != 6) {
                            return 0;
                        }
                        break;
                    }
                    case 2:{
                        if (table[i][j] != 5) {
                            return 0;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }
    }
    return 1;
}

TreeNode::TreeNode(int **table, int i, int j):table(table), i(i), j(j),parent(NULL) {}

TreeNode::TreeNode() {
    int table[3][3] = {{2,0,3},{1,8,4},{7,6,5}};
    this->table = new int*[3];
    for (int index=0;index<3;index++) {
        this->table[index] = new int[3];
    }
    for (int _i=0;_i<3;_i++) {
        for (int _j=0; _j<3;_j++) {
            this->table[_i][_j] = table[_i][_j];
        }
    }
    this->i = 0;
    this->j = 1;
    this->g = 0;
    this->h = computeH();
    this->f = g + h;
    parent=NULL;
}


