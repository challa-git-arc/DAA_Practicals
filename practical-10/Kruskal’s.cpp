#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int n, e;
    Edge edges[100];

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, edges + e, compare);

    int total = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            total += edges[i].weight;
            unite(u, v);
        }
    }

    cout << "Minimum Cost = " << total;

    return 0;
}