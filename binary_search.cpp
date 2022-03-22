#include <bits/stdc++.h>
using namespace std;

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

// returns the last x in the range [lo,hi] such that f(x) = true
ll lastTrue(ll lo, ll hi, function<bool(ll)> f) {
  for (--lo; lo < hi;) {
    ll mid = lo + (hi - lo + 1) / 2;
    if (f(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  return lo;
}

// returns the first x in the range [lo,hi] such that f(x) = true
ll firstTrue(ll lo, ll hi, function<bool(ll)> f) {
  for (hi++; lo < hi;) {
    ll mid = lo + (hi - lo) / 2;
    if (f(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int lo, mid, high;
  lo = 0;
  high = n;  // lo inclusive, high not inclusive
  while (lo < high) {
    mid = lo + (high - lo) / 2;
    cout << mid << endl;
    if (arr[mid] >= x)
      high = mid;
    else
      lo = mid + 1;
  }
}