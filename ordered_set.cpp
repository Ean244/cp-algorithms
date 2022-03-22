#include <bits/stdc++.h>
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//warning: lower_bound works as upper_bound!
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
template <class K, class V>
using ordered_map =
    tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back

#define all(x) x.begin(), x.end()
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ordered_set<ii> s;
}