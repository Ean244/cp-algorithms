#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;

const int INF = 1e9;
const ll INFL = 1e18;

const int size = 1e4;
ll dp[size + 5];

int pointer = 0;
ll factorial(int n) {
  if (n < 0) return 0;
  if (pointer >= n) {
    return dp[n];
  }

  while (pointer <= n) {
    ++pointer;
    dp[pointer] = dp[pointer - 1] * pointer;
  }
  return dp[n];
}

ll choose(int n, int k) {
  if (k > n / 2) {
    k = n - k;
  }
  return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  dp[0] = 1;
  cout << __gcd(18, 27);
  cout << choose(25, 2);
}