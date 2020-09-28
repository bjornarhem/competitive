// https://open.kattis.com/problems/walkforest

#include <bits/stdc++.h>

using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	long long n, m;
    long long INF = 1000000000000000000;
	while (true) {
		cin >> n;
		if (n==0) { 
            return 0; 
        }
		cin >> m;

        vector<vector<long long>> graph;
        for (long long i = 0; i < n; i++) {
            vector<long long> row(n, INF);
            graph.push_back(row);
        }

        for (long long i = 0; i < m; i++) {
            long long u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        vector<long long> dist(n, INF);
        dist[1] = 0;
        vector<bool> knowDist(n,0);
        knowDist[1] = 1;
        long long last_node = 1;
        vector<long long> nodesSorted = {last_node};
    
        for (long long i = 0; i < n-1; i++) {
            long long smallest_dist = INF;
            long long smallest_dist_node = -1;
            for (long long j = 0; j < n; j++) {
                if (!knowDist[j]){
                    dist[j] = min(dist[j], dist[last_node] + graph[last_node][j]);
                    if (dist[j] < smallest_dist) {
                        smallest_dist = dist[j];
                        smallest_dist_node = j;
                    }
                }
            }
            if (smallest_dist_node == -1) { break; }
            last_node = smallest_dist_node;
            knowDist[last_node] = 1;
            nodesSorted.push_back(last_node);
        }

		vector<long long> paths(n, 0);
		paths[0] = 1;

		for (long long i = nodesSorted.size() - 1; i >= 0; i--) {
			long long fra = nodesSorted[i];
			for (long long til = 0; til < n; til++) {
                if (graph[fra][til] < INF) {
				    if (dist[fra] > dist[til]) {
					    paths[til] += paths[fra];
				    }
                }
			}
		}

		cout << paths[1] << endl;
	}
}
