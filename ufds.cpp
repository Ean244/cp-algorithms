#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;

const int INF = 1e9;
const ll INFL = 1e18;

int S[100005];
ll p[100005];
int findSet(int v) {
  if (S[v] == v) return v;
  int root = findSet(S[v]);
  S[v] = root;
  return root;
}

bool sameSet(int a, int b) { return findSet(a) == findSet(b); }

void mergeSet(int a, int b) { S[findSet(b)] = findSet(a); }

int n, m;
int a, b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    S[i] = i;
  }

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    if (sameSet(a, b)) {
      cout << -1 << endl << flush;
      continue;
    }

    if (p[findSet(a)] > p[findSet(b)]) {
      cout << findSet(a) << endl << flush;
      mergeSet(a, b);
    } else {
      cout << findSet(b) << endl << flush;
      mergeSet(b, a);
    }
  }
}