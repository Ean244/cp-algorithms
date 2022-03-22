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

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;

struct mi {
  int v;
  explicit operator int() const { return v; }
  mi() { v = 0; }
  mi(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi& operator-=(mi& a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }  // a has been modified!
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pw(mi a, ll p) {
  assert(p >= 0);
  return p == 0 ? 1 : pw(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
  assert(a.v != 0);
  return pw(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}