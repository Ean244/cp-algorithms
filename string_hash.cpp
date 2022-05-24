#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_PROJECT
#else
#define cerr \
  if (false) cerr
#endif

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

typedef long long ll;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;

#define SIZE(a) (int)(a).size()
#define endl '\n'
#define all(x) x.begin(), x.end()
#define ALL(x) begin(x), end(x)

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}