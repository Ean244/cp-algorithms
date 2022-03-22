#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PROJECT
#else
#define cerr \
  if (false) cerr
#endif

#define f first
#define s second
#define pb push_back

#define all(x) x.begin(), x.end()
#define ALL(x) begin(x), end(x)
#define FOR(i, a) for (int i = 0; i < (a); i++)
#define SZ(a) (int)(a).size()

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vll;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;
const int sz = 2e5 + 5;

const int block_size = 350;
int answer = 0;
int freq[100005];
vi v;

struct Query {
  int l, r, idx;

  bool operator<(Query other) const {
    return ii(floor(l / block_size), r) < ii(floor(other.l / block_size), other.r);
  }
};

void add(int i) {
  if (v[i] > 1e5) return;

  freq[v[i]]++;
  if (freq[v[i]] == v[i] + 1) {
    answer--;
  }

  if (freq[v[i]] == v[i]) {
    answer++;
  }
}

void remove(int i) {
  if (v[i] > 1e5) return;

  freq[v[i]]--;
  if (freq[v[i]] == v[i]) {
    answer++;
  }

  if (freq[v[i]] == v[i] - 1) {
    answer--;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
#ifdef LOCAL_PROJECT
#else
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif

  int n, q;
  cin >> n >> q;

  v = vi(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  vi res(q);

  vector<Query> queries;
  for (int i = 0; i < q; ++i) {
    Query query;
    cin >> query.l >> query.r;
    --query.l;
    --query.r;
    query.idx = i;

    queries.pb(query);
  }

  sort(all(queries));

  int curr_l = 0;
  int curr_r = -1;
  for (auto q : queries) {
    while (curr_l > q.l) {
      curr_l--;
      add(curr_l);
    }

    while (curr_r < q.r) {
      curr_r++;
      add(curr_r);
    }

    while (curr_l < q.l) {
      remove(curr_l);
      curr_l++;
    }

    while (curr_r > q.r) {
      remove(curr_r);
      curr_r--;
    }

    res[q.idx] = answer;
  }

  for (auto v : res) {
    cout << v << endl;
  }
}