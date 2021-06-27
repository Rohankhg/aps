#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    long long x;
    cin >> n >> x;
    vector<vector<long long>> a(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<long long>> d(n);
    for (int t = 0; t < (1 << (n - 1)); t++) {
      long long s = a[0][0];
      int i = 0, j = 0;
      for (int k = 0; k < n - 1; k++) {
        if (t & (1 << k)) {
          ++i;
        } else {
          ++j;
        }
        s += a[i][j];
      }
      d[i].push_back(s);
    }
    for (int i = 0; i < n; i++) {
      sort(d[i].begin(), d[i].end());
    }
    long long ans = 0;
    for (int t = 0; t < (1 << (n - 1)); t++) {
      long long s = a[n - 1][n - 1];
      int i = n - 1, j = n - 1;
      for (int k = 0; k < n - 1; k++) {
        if (t & (1 << k)) {
          --i;
        } else {
          --j;
        }
        s += a[i][j];
      }
      s -= a[i][j];
      long long bound = x - s + 1;
      int pos = (int) (lower_bound(d[i].begin(), d[i].end(), bound) - d[i].begin());
      ans += pos;
    }
    cout << ans << '\n';
  }
  return 0;
}
