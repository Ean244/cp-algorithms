#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;

const int INF = 1e9;
const ll INFL = 1e18;

struct node {
  int s, e, m;
  int lazy = 0;
  int val = 0;
  node *l, *r;
  node(int S, int E) {
    s = S;
    e = E;
    m = (s + e) / 2;
    l = nullptr;
    r = nullptr;
  }

  void create() {
    if (s != e) {
      l = new node(s, m);
      r = new node(m + 1, e);
    }
  }

  void propagate() {
    // if (lazy == 0) return;
    val += (e - s + 1) * lazy;
    if (s != e) {
      if (l == nullptr) create();
      l->lazy += lazy;
      r->lazy += lazy;
    }
    lazy = 0;
  }

  void increment(int S, int E, int v) {
    if (s == S and e == E) {
      lazy += v;
    } else {
      if (l == nullptr) create();
      if (E <= m) {
        l->increment(S, E, v);
      } else if (S > m) {
        r->increment(S, E, v);
      } else {
        l->increment(S, m, v);
        r->increment(m + 1, E, v);
      }
      l->propagate();
      r->propagate();
      val = l->val + r->val;
    }
  }

  int query(int S, int E) {
    if (l == nullptr) create();
    propagate();

    if (s == S and e == E)
      return val;
    else if (E <= m)
      return l->query(S, E);
    else if (S > m)
      return r->query(S, E);
    else
      return l->query(S, m) + r->query(m + 1, E);
  }
};

node *root = new node(1, 1e9);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    int j;
    cin >> j;
    if (j == 1) {
      int l, r, k;
      cin >> l >> r >> k;
      root->increment(l, r, k);
    } else {
      int l, r;
      cin >> l >> r;
      cout << root->query(l, r) << endl;
    }
  }
}