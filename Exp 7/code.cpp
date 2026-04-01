#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for (auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    queue<tuple<int,int,int>> q;
    q.push({src, 0, 0});

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!q.empty()) {
        auto [node, cost, stops] = q.front();
        q.pop();

        if (stops > k) continue;

        for (auto &it : adj[node]) {
            int next = it.first;
            int price = it.second;

            if (cost + price < dist[next]) {
                dist[next] = cost + price;
                q.push({next, dist[next], stops + 1});
            }
        }
    }

    if (dist[dst] == INT_MAX) return -1;
    return dist[dst];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}
