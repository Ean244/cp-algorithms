 #include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
  vii adj[100005];                          // Weight, Node
  priority_queue<ii, vii, greater<ii>> pq;  // Weight, Node
  int dist[100005];
  int V, E;
  fill(dist, dist + 100005, INF);
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    --x;
    --y;
    adj[x].emplace_back(w, y);
    adj[y].emplace_back(w, x);
  }

  pq.emplace(0, 0);
  dist[0] = 0;
  while (!pq.empty()) {
    ii u = pq.top();
    pq.pop();
    if (u.first != dist[u.second]) continue;
    for (auto v : adj[u.second]) {
      if (dist[v.second] > u.first + v.first) {
      	dist[v.second] = u.first + v.first;
      	pq.emplace(dist[v.second], v.second);
      }
    }
  }
  cout << dist[V - 1];
}