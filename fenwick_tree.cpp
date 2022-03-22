#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

#define all(x) x.begin(), x.end()
#define ALL(x) begin(x), end(x)
#define FOR(i, a) for (int i=0; i<(a); i++)

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vll;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;
const int sz = 1e6;

ll tree[sz];

// NOTE: only increment is supported
void increment(int U, int v) {
	int i = U;
	while (i < sz) {
		tree[i] += v;
		i += (i & -i);
	}
}

ll query(int E) {
	ll res = 0;
	int i = E;
	while (i > 0) {
		res += tree[i];
		i -= (i & -i);
	}
	return res;
}

ll query(int S, int E) {
	return query(E) - query(S - 1);
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    
}