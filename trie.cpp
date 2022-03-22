#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PROJECT
#else
    #define cerr if(false)cerr
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

struct trie {
	vector<array<int, 2> > entries;
	int id = 1;
	
	trie() {
		entries.pb({-1, -1});
	}
	
	void add(int x) {
		int node = 0;
		for (int i = lg - 1; i >= 0; --i) {
			int bit = ((x >> i) & 1);
			if (entries[node][bit] == -1) {
				entries.pb({-1, -1});
				entries[node][bit] = id++;
			}
			
			node = entries[node][bit];
		}
	}
	
	int mx(int x) {
		int node = 0;
		int res = 0;
		for (int i = lg - 1; i >= 0; --i) {
			int bit = (x >> i) & 1;
			if (entries[node][bit ^ 1] == -1) {
				node = entries[node][bit];
			} else {
				res |= (1 << i);
				node = entries[node][bit ^ 1];
			}
		}
		return res;
	}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL_PROJECT
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
	trie root;
	
	
}