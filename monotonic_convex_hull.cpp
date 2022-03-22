#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1000000007;

#define SIZE(a) (int)(a).size()
#define endl '\n'
#define all(x) x.begin(), x.end()
#define ALL(x) begin(x), end(x)

int arr[1000005];
int dp[1000005];
int pre[1000005];
deque<ii> dq;

int f(ii line, int x) { return line.first * x + line.second; }

long double intersect(int m1, int c1, int m2, int c2) {
  return (long double)(c2 - c1) / (m1 - m2);
}

long double intersect(ii a, ii b) {
  return intersect(a.first, a.second, b.first, b.second);
}

void insert(ii line) {
  while (dq.size() > 1) {
    int s = dq.size();
    if (intersect(dq[s - 1], dq[s - 2]) >= intersect(dq[s - 2], line)) {
      dq.pop_back();
    } else {
      break;
    }
  }
  dq.push_back(line);
}

int query(int x) {
  while (dq.size() > 1) {
    if (f(dq[0], x) < f(dq[1], x))
      dq.pop_front();
    else
      break;
  }
  return f(dq[0], x);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pre[i] = arr[i];
  }

  for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];

  fill(ALL(dp), -INFL);

  dp[0] = 0;
  insert(ii(0, 0));
  for (int i = 1; i <= n; ++i) {
    dp[i] = a * pre[i] * pre[i] + b * pre[i] + c + query(pre[i]);
    insert(ii(-2 * a * pre[i], a * pre[i] * pre[i] - b * pre[i] + dp[i]));
  }

  for (int i = 0; i <= n; ++i) cerr << dp[i] << " ";
  
  cout << dp[n];
}