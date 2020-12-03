#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
private:
    int verTexCount;  //图的顶点数
    int edgeCount;  //图的边数
    vector<int> verTexs; //顶点数组  char ** verTexs[MAX_VERTEX];
    vector<vector<int>> edge; //边/弧 邻接矩阵 可以表示出weight权值  int arc[MAX_VERTEX];
public:
    // n顶点个数,m有向边的个数,s源点序号,t汇点序号
    Graph(int n,int m); 
    ~Graph();
    void insert_vertex(int num, int v);
    void insert_edge(int u, int v, int flow);
    void show_Graph();
    bool GraphIsAdjacent(int u, int v);
    // void DFS(int start, int end, int &flow);
    void BFS(vector<vector<vector<int>>> &dp, int start, int K);
    int maxTotalWeight(int K);
    // void BFS(int start, int end);
    // vector<vector<int>> reverseFlow();
};

Graph::Graph(int n,int m){
    verTexCount = n;
    edgeCount = m;
    vector<int> elementVer(verTexCount, 0);
    verTexs = elementVer;
    vector<vector<int>> elementVer2(verTexCount, elementVer);
    edge = elementVer2;
}

Graph::~Graph(){
}

void Graph::insert_vertex(int num, int v){
    verTexs[num] = v;
}

void Graph::insert_edge(int u, int v, int flow){
    int u_index = -1;
    int v_index = -1;
    for(int i = 0; i < verTexCount; ++i){
        if(verTexs[i] == u){
            u_index = i;
        }
        if(verTexs[i] == v){
            v_index = i;
        }
    }
    edge[u_index][v_index] = flow;
}

bool Graph::GraphIsAdjacent(int u, int v){
	int u_index = 0;
    int v_index = 0;
    for(int i = 0; i < verTexCount; ++i){
        if(verTexs[i] == u){
            u_index = i;
        }
        if(verTexs[i] == v){
            v_index = i;
        }
    }
    return edge[u_index][v_index];
}

void Graph::show_Graph(){
    cout << "       ";
    for(int i = 0; i < verTexCount; ++i){
        cout << verTexs[i] << "     ";
    }
    putchar(10);
    for(int i = 0; i < verTexCount; ++i){
        cout << "顶点" << verTexs[i] << ": ";
        for(int j = 0; j < verTexCount; ++j){
            cout << edge[i][j] << "     ";
        }
        putchar(10);
    }
}

void Graph::BFS(vector<vector<vector<int>>> &dp, int start, int K){
    queue<int> element;
    int res = 0;
    int k = 1;
    element.push(start);
    int a = 0;
    while(!element.empty()){
        if(k > K){
            return;
        }
        int level = element.size();
        // int tmp = 0;
        for(int n = 0; n < level; ++n){
            int curr = element.front();
            // cout << "curr = " << curr << " ";
            // cout << "k = " << k << endl;
            element.pop();
            for(int i = 0; i < verTexCount; ++i){
                // cout << "i = " << i << endl;
                if(GraphIsAdjacent(curr, i)){
                    // cout << " 里:" << "i = " << i << " ";
                    // cout << " " << dp[start][curr][k] + edge[curr][i] << " - ";
                    // cout << dp[start][i][k + 1] << endl;
                    if(dp[start][curr][k] + edge[curr][i] > dp[start][i][k + 1]){
                        // cout << "------- " << i << endl;
                        dp[start][i][k + 1] = dp[start][curr][k] + edge[curr][i];
                        element.push(i);
                        // tmp = i;
                    }
                }
            }
            if(n == level - 1){
                k++;
            }
        }
    }
}

int Graph::maxTotalWeight(int K){
    vector<vector<vector<int>>> dp(verTexCount, vector<vector<int>>(verTexCount, vector<int>(verTexCount, 0)));
    for(int i = 0; i < verTexCount; ++i){
        for(int j = 0; j < verTexCount; ++j){
            dp[i][j][1] = edge[i][j];
        }
    }

    int maxRes = 0;
    for(int i = 0; i < verTexCount; ++i){
        BFS(dp, verTexs[i], K);
    }

    for(int i = 0; i < verTexCount; ++i){
        cout << "顶点: " << i << "  ";
        for(int j = 0; j < verTexCount; ++j){
            cout << dp[i][j][K + 1] << " ";
            if(dp[i][j][K + 1] > maxRes){
                maxRes = dp[i][j][K + 1];
            }
        }
        putchar(10);
    }
    return maxRes;
}

int main(){
    Graph a(6, 8);
    for(int i = 0; i < 6; ++i){
        a.insert_vertex(i, i);
    }
    a.insert_edge(0, 1, 6);
    a.insert_edge(5, 0, 1);
    a.insert_edge(5, 2, 2);
    a.insert_edge(2, 3, 3);
    a.insert_edge(2, 0, 4);
    a.insert_edge(3, 4, 1);
    a.insert_edge(1, 3, 1);
    a.insert_edge(1, 4, 2);
    a.show_Graph();
    putchar(10);

    int K = 4;
    // int res = a.BFS(dp, 5, K);
    int res = a.maxTotalWeight(K);
    cout << "res = " << res << endl;

    return 0;
}
