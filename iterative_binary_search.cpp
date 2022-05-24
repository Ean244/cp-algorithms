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

bool f(int x) {
  if (x > n) return false;
  // impl
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
#ifdef LOCAL_PROJECT
#else
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif
  int hi;
  int curr = 0;
  for (int x = 1<<int(floor(log2(hi))); x; x >>= 1) {
  	if (x + curr <= hi and f(x + curr)) curr += x;
  }
  cout << curr;
}