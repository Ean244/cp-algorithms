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

ll blocks[450];
int nums[sz];
int k;

ll query(int u) {
	ll res = 0;
	for (int i = 0; i < u / k; ++i) res += blocks[i];
	for (int i = floor(u / k) * k; i < u; ++i) {
		res += nums[i];
	}
	return res;
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
  
  k = floor(sqrt(n));

  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
    blocks[i / k] += nums[i];
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, u;
      cin >> p >> u;
      --p;
      blocks[p / k] -= nums[p];
      blocks[p / k] += u;
      nums[p] = u;
    } else {
    	int l, r;
    	cin >> l >> r;
    	--l;
    	cout << (query(r) - query(l)) << endl;
    }
  }
}