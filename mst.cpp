#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

#define all(x) x.begin(), x.end()
#define ALL(x) begin(x), end(x)
#define FOR(i, a) for (int i = 0; i < (a); i++)

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vll;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;
const int sz = 2e4 + 5;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
#ifdef LOCAL_PROJECT
#else
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w"l, stdout);
#define cerr \
  if (false) cerr
#endif
  int n, m;
  while (true) {
    cin >> n >> m;
    cerr << n << " " << m << endl;
    if (n == 0) break;

    vector<vii> adj(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].pb({v, w});
    }

    priority_queue<ii, vector<ii>, greater<ii> > q;
    vector<bool> taken(n);
    vi prev(n);
    vi val(n, INF);
    q.push({0, 0});
    ll cost = 0;
    vii res;
    while (!q.empty()) {
      ii x = q.top();
      q.pop();
      int u, w;
      tie(w, u) = x;

      if (taken[u]) continue;
      taken[u] = true;
      cost += w;

      if (u != 0) res.pb({min(prev[u], u), max(prev[u], u)});

      for (auto y : adj[u]) {
        int v, wt;
        tie(v, wt) = y;
        if (wt > val[v]) continue;
        prev[v] = u;
        val[v] = wt;
        q.push({wt, v});
      }
    }

    bool f = false;
    for (int i = 0; i < n; ++i) {
      if (!taken[i]) {
        cout << "Impossible" << endl;
        f = true;
        break;
      }
    }

    if (f) continue;

    sort(all(res));
    cout << cost << endl;
    for (auto v : res) {
      cout << v.f << " " << v.s << endl;
    }
  }
}