#include <bits/stdc++.h>

using namespace std;

struct C_HASH {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef long long ll;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;

#define SIZE(a) (int)(a).size()
#define endl '\n'
#define all(x) x.begin(), x.end()
#define ALL(x) begin(x), end(x)

#ifdef LOCAL_PROJECT
#else
#define cerr \
  if (false) cerr
#endif

struct que {
  priority_queue<ll, vector<ll>, greater<ll> > a, b;
  void push(ll x) { a.push(x); }
  void del(ll x) { b.push(x); }
  void update() {
    while (!b.empty() and a.top() == b.top()) {
      a.pop();
      b.pop();
    }
  }
  ll top() {
    update();
    return a.top();
  }
  void pop() {
    update();
    a.pop();
  }

  int size() { return (int)(a.size() - b.size()); }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}