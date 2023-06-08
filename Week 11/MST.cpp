#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> graph = {
    {0, 3, 0, 0, 0, 1},
    {3, 0, 2, 1, 10, 0},
    {0, 2, 0, 3, 0, 5},
    {0, 1, 3, 0, 5, 0},
    {0, 10, 0, 5, 0, 4},
    {1, 0, 5, 0, 4, 0}
};

vector<int> primMST(int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> minWeight(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push(make_pair(0, startVertex));
    minWeight[startVertex] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (graph[u][v] < minWeight[v]) {
                    minWeight[v] = graph[u][v];
                    parent[v] = u;
                    pq.push(make_pair(minWeight[v], v));
                }
            }
        }
    }

    return parent;
}

void printMST(const vector<int>& parent, int startVertex) {
    int numVertices = graph.size();
    cout << "Minimum Spanning Tree Edges:\n";

    for (int i = 0; i < numVertices; i++) {
        if (i != startVertex) {
            cout << parent[i] << " - " << i << "  (Weight: " << graph[i][parent[i]] << ")\n";
        }
    }
}

int main() {
    int startVertex = 0;
    vector<int> parent = primMST(startVertex);
    printMST(parent, startVertex);

    return 0;
}
