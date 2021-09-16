// https://open.kattis.com/problems/minspantree

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
    private:
        vector<int> p, rank, setSize;
        int numSets;
    public:
        UnionFind(int N) {
            setSize.assign(N, 1);
            numSets = N;
            rank.assign(N, 0);
            p.assign(N, 0);
            for (int i = 0; i < N; i++)
                p[i] = i;
        }
        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                numSets--;
                int x = findSet(i), y = findSet(j);
                if (rank[x] > rank[y]) {
                    p[y] = x;
                    setSize[x] += setSize[y];
                } else {
                    p[x] = y;
                    setSize[y] += setSize[x];
                    if(rank[x] == rank[y])
                        rank[y]++;
                }
            }
        }
        int numDisjointSets() { return numSets; }
        int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

struct sEdge {
    int u, v;
    int weight;
    sEdge () {}
    bool operator< (const sEdge &other) const {
        return weight < other.weight;
    }
};

bool lexSort(sEdge i, sEdge j) {
    return min(i.u, i.v) != min(j.u, j.v) ? min(i.u, i.v) < min(j.u, j.v) : max(i.u, i.v) < max(j.u, j.v);
}

int main() {
    int n, m;
    cin >> n >> m;

    while (n != 0) {
    vector<sEdge> edge(m);

    for (int i = 0; i < m; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].weight;

    sort(edge.begin(), edge.end());

    UnionFind UF(n);
    vector<sEdge> minSpanTree;
    int sum = 0;

    for (int i = 0; i < edge.size(); i++) {
        if (!UF.isSameSet(edge[i].u, edge[i].v)) {
            UF.unionSet(edge[i].u, edge[i].v);
            minSpanTree.push_back(edge[i]);
            sum += edge[i].weight;
        }
    }

    if (minSpanTree.size() != n-1){
        cout << "Impossible" << endl;
    }
    else {
        cout << sum << endl;
        sort(minSpanTree.begin(), minSpanTree.end(), lexSort);
        for (int i = 0; i < minSpanTree.size(); i++) {
            cout << min(minSpanTree[i].u, minSpanTree[i].v) << " ";
            cout << max(minSpanTree[i].u, minSpanTree[i].v) << endl;
        }
    }

    cin >> n >> m;
    }
}
